#include "kt.h"
#include "kt_thread.h"
#include "kt_sbucket.h"
#include <stdbool.h>
#include <inttypes.h>
#include <omp.h>
#ifndef DYNAMIC_CHUNK
#define DYNAMIC_CHUNK 16
#endif
#ifndef MIN_PAR_SIZE
#define MIN_PAR_SIZE 1
#endif
#define TIMER_PADDING 8
static double frontier_times[KT_MAX_THREADS * TIMER_PADDING] = { 0. };
static double update_times[KT_MAX_THREADS * TIMER_PADDING]   = { 0. };
typedef struct
{
int32_t vj;
int32_t dec;
int32_t inc;
} aii_s;
typedef struct
{
int64_t start;
int64_t end;
} xaii_s;
typedef struct
{
int32_t nvtxs;
int64_t nedges; 
int64_t total_support;
int32_t * supports;
ssize_t * ids;
xaii_s * xaii;
aii_s  * aii;
} dyn_graph_t;
static dyn_graph_t * p_dgraph_alloc(
int32_t const nvtxs,
int64_t const nedges)
{
dyn_graph_t * d_graph = gk_malloc(sizeof(*d_graph), "d_graph");
d_graph->nvtxs  = nvtxs;
d_graph->nedges = nedges;
d_graph->xaii = gk_malloc((nvtxs+1) * sizeof(*d_graph->xaii), "xaii");
d_graph->aii  = gk_malloc((2*nedges+1) * sizeof(*d_graph->aii), "aii");
d_graph->ids  = gk_malloc((2*nedges+1) * sizeof(*d_graph->ids), "ids");
d_graph->supports = gk_malloc(nedges * sizeof(*d_graph->supports), "supports");
par_memset(d_graph->xaii,  0, (nvtxs + 1) * sizeof(*d_graph->xaii));
par_memset(d_graph->aii,   0, (2 * nedges + 1) * sizeof(*d_graph->aii));
par_memset(d_graph->supports, 0, nedges * sizeof(*d_graph->supports));
size_t bytes = 0;
bytes += (nvtxs + 1) * sizeof(*d_graph->xaii);
bytes += (2 * nedges + 1) * sizeof(*d_graph->aii);
bytes += (2 * nedges + 1) * sizeof(*d_graph->ids);
bytes += nedges * sizeof(*d_graph->supports);
printf("DYN-GRAPH-BYTES: %0.2fGB\n",
(double) bytes / (1024 * 1024 * 1024));
return d_graph;
}
static void p_dgraph_free(
dyn_graph_t * d_graph)
{
gk_free((void **) &d_graph->aii, LTERM);
gk_free((void **) &d_graph->xaii, LTERM);
gk_free((void **) &d_graph->ids, LTERM);
gk_free((void **) &d_graph->supports, LTERM);
gk_free((void **) &d_graph, LTERM);
}
static void p_init_dgraph(
dyn_graph_t * dgraph,
gk_graph_t const * const ugraph,
edge_t * const edges)
{
int32_t const nvtxs = ugraph->nvtxs;
ssize_t const * const restrict xadj = ugraph->xadj;
int32_t const * const restrict adjncy = ugraph->adjncy;
int32_t const * const restrict adjwgt = ugraph->iadjwgt;
xaii_s * const restrict xaii = dgraph->xaii;
aii_s  * const restrict aii = dgraph->aii;
ssize_t * const restrict ids = dgraph->ids;
int32_t * const restrict supports = dgraph->supports;
#pragma omp parallel for
for(int32_t vi=0; vi < nvtxs; ++vi) {
dgraph->xaii[vi].start = 0;
}
int64_t edge_ptr = 0;
for(int32_t vi=0; vi < nvtxs; ++vi) {
for(ssize_t ei = xadj[vi]; ei < xadj[vi+1]; ++ei) {
if (adjwgt[ei] == 0) {
continue;
}
xaii[vi].start++;
xaii[adjncy[ei]].start++;
edges[edge_ptr].vi = vi;
edges[edge_ptr].vj = adjncy[ei];
supports[edge_ptr] = adjwgt[ei];
edge_ptr++;
}
}
for(int32_t vi=1; vi < nvtxs; ++vi) {
xaii[vi].start += xaii[vi-1].start;
}
for(int32_t vi=nvtxs; vi > 0; --vi) {
xaii[vi].start = xaii[vi-1].start;
}
xaii[0].start = 0;
edge_ptr = 0;
for(int32_t vi=0; vi < nvtxs; ++vi) {
for(ssize_t ei = xadj[vi]; ei < xadj[vi+1]; ++ei) {
if (adjwgt[ei] == 0) {
continue;
}
int32_t const vj = adjncy[ei];
aii[xaii[vj].start].vj  = vi;
aii[xaii[vj].start].inc = 1;
aii[xaii[vj].start].dec = 1;
ids[xaii[vj].start]     = edge_ptr;
edges[edge_ptr].eji     = xaii[vj].start++;
edge_ptr++;
}
}
edge_ptr = 0;
for(int32_t vi=0; vi < nvtxs; ++vi) {
for(ssize_t ei = xadj[vi]; ei < xadj[vi+1]; ++ei) {
if (adjwgt[ei] == 0) {
continue;
}
aii[xaii[vi].start].vj  = adjncy[ei];
aii[xaii[vi].start].inc = 1;
aii[xaii[vi].start].dec = 1;
ids[xaii[vi].start]     = edge_ptr;
edges[edge_ptr].eij     = xaii[vi].start++;
edge_ptr++;
}
}
for(int32_t vi=nvtxs; vi > 0; --vi) {
xaii[vi].start = xaii[vi-1].start;
}
xaii[0].start = 0;
for(int32_t vi=0; vi < nvtxs; ++vi) {
xaii[vi].end = xaii[vi+1].start;
}
}
static inline void p_intersect_lists(
dyn_graph_t * const dgraph,
int32_t const vi,
int32_t const vj,
thread_ws * ws,
int32_t const * const supports,
int64_t const edge_id,
int32_t const min_support)
{
assert(vi < vj);
int32_t num_triangles = supports[edge_id];
xaii_s const * const restrict xaii = dgraph->xaii;
aii_s const * const restrict aii   = dgraph->aii;
ssize_t const * const restrict ids = dgraph->ids;
int64_t ei      = xaii[vi].end-1;
int64_t ej      = xaii[vj].end-1;
int64_t const eistart = xaii[vi].start;
int64_t const ejstart = xaii[vj].start;
while (ei >= eistart && ej >= ejstart) {
int32_t const vik = aii[ei].vj;
int32_t const vjk = aii[ej].vj;
if (vik > vjk) {
ei  -= aii[ei].dec;
} else if (vjk > vik) {
ej  -= aii[ej].dec;
} else {
int32_t const edge_ei = ids[ei];
int32_t const edge_ej = ids[ej];
int64_t const min_edge         = gk_min(edge_ei, edge_ej);
int32_t const min_edge_support = supports[min_edge];
int64_t min_deleted_edge = edge_id;
if((edge_ei < edge_id) && (supports[edge_ei] < min_support)) {
min_deleted_edge = edge_ei;
} else if((edge_ej < edge_id) && (supports[edge_ej] < min_support)) {
min_deleted_edge = edge_ej;
}
if(edge_id == min_deleted_edge) {
triangle_t tri;
tri.u = gk_min(vi, vik);
tri.v = gk_min(gk_max(vi, vik), vj);
tri.w = gk_max(vik, vj);
tri.uv = edge_ei;
tri.vw = edge_ej;
int const dest = map_vtx_to_bucket(tri.u, ws);
send_thread_tri_msg(&tri, dest, ws);
}
if(--num_triangles == 0) {
break;
}
ei  -= aii[ei].dec;
ej  -= aii[ej].dec;
}
}
}
static inline void p_delete_edge(
xaii_s * const restrict xaii,
aii_s  * const restrict aii,
int32_t const vi,
int64_t const e_id)
{
if(e_id == xaii[vi].start) {
xaii[vi].start += aii[e_id].inc;
} else {
aii[e_id - aii[e_id].dec].inc += aii[e_id].inc;
}
if(e_id == xaii[vi].end - 1) {
xaii[vi].end -= aii[e_id].dec;
} else {
aii[e_id + aii[e_id].inc].dec += aii[e_id].dec;
}
}
static void p_serial_peel(
dyn_graph_t * dgraph,
edge_t * const edges,
int32_t const ktruss,
int64_t * const restrict frontier_buf,
int64_t const frontier_size,
support_bucket_t * sbuckets,
thread_ws * * thd_ws)
{
}
static int64_t p_gen_frontier(
dyn_graph_t * dgraph,
edge_t * const edges,
int32_t const ktruss,
int64_t * const restrict frontier_buf,
int64_t const frontier_size,
thread_ws * * thd_ws)
{
xaii_s * const restrict xaii = dgraph->xaii;
aii_s  * const restrict aii = dgraph->aii;
int32_t * const restrict supports = dgraph->supports;
int32_t const min_support = ktruss - 2;
int64_t delta_support = 0;
int64_t delta_edges = 0;
#pragma omp parallel reduction(+: delta_edges, delta_support) if(frontier_size >= MIN_PAR_SIZE)
{
int const tid = omp_get_thread_num();
double my_timer;
gk_clearwctimer(my_timer);
gk_startwctimer(my_timer);
#pragma omp for schedule(dynamic, DYNAMIC_CHUNK) nowait
for(int64_t e_ptr = 0; e_ptr < frontier_size; ++e_ptr) {
int64_t const e = frontier_buf[e_ptr];
assert(supports[e] < min_support);
if(supports[e] > 0) {
int32_t const vi = edges[e].vi;
int32_t const vj = edges[e].vj;
assert(vi < vj);
p_intersect_lists(dgraph, vi, vj, thd_ws[tid], supports, e,
min_support);
}
epair_t msg;
msg.key  = edges[e].vi;
msg.val = edges[e].eij;
send_thread_epair_msg(&msg,
map_vtx_to_bucket(msg.key, thd_ws[tid]),
thd_ws[tid]);
msg.key = edges[e].vj;
msg.val = edges[e].eji;
send_thread_epair_msg(&msg,
map_vtx_to_bucket(msg.key, thd_ws[tid]),
thd_ws[tid]);
++delta_edges;
delta_support += supports[e];
supports[e] = -(ktruss - 1);
} 
gk_stopwctimer(my_timer);
#pragma omp barrier
gk_startwctimer(my_timer);
int const num_buckets = thd_ws[tid]->num_buckets;
#pragma omp for schedule(dynamic, 1) nowait
for(int bucket=0; bucket < num_buckets; ++bucket) {
int64_t num_del_edges = 0;
epair_t * const del_pairs =
get_incoming_epair_bucket(thd_ws, bucket, &num_del_edges);
for(int32_t m=0; m < num_del_edges; ++m) {
int64_t const e_id = del_pairs[m].val;
int32_t const vi = del_pairs[m].key;
p_delete_edge(xaii, aii, vi, e_id);
}
} 
gk_stopwctimer(my_timer);
frontier_times[omp_get_thread_num() * TIMER_PADDING] = my_timer;
} 
dgraph->total_support -= delta_support;
return delta_edges;
}
static int64_t p_update_supports(
dyn_graph_t * dgraph,
edge_t * edges,
int32_t const ktruss,
support_bucket_t * sbuckets,
thread_ws * * thd_ws,
int64_t const frontier_size)
{
int const num_buckets = thd_ws[0]->num_buckets;
int32_t * const restrict supports = dgraph->supports;
int64_t nchanges = 0;
#pragma omp parallel reduction(+: nchanges) if(frontier_size > MIN_PAR_SIZE)
{
int const tid      = omp_get_thread_num();
int const nthreads = omp_get_num_threads();
double my_timer;
gk_clearwctimer(my_timer);
gk_startwctimer(my_timer);
#pragma omp for schedule(dynamic, 1) nowait
for(int bucket=0; bucket < num_buckets; ++bucket) {
int32_t num_triangles = 0;
triangle_t * const triangles =
get_incoming_triangle_bucket(thd_ws, bucket, &num_triangles);
for(int t=0; t < num_triangles; ++t) {
triangle_t const * const tri = &(triangles[t]);
assert(tri->u < tri->v);
assert(tri->v < tri->w);
assert(tri->uv < dgraph->nedges);
assert(tri->vw < dgraph->nedges);
int64_t const edge_id = tri->uv;
if(supports[edge_id] > 0) {
supports[edge_id]--;
if(map_edge_to_bucket(edge_id, thd_ws[tid]) == bucket) {
sbucket_update_edge(&(sbuckets[bucket]), edge_id, supports[edge_id],
ktruss);
} else {
int const edge_bucket = map_edge_to_bucket(edge_id, thd_ws[tid]);
send_thread_edge_msg(edge_id, edge_bucket, thd_ws[tid], 1);
}
++nchanges;
}
int const bucket_dest = map_vtx_to_bucket(tri->w, thd_ws[tid]);
if(bucket_dest == tri->w) {
int64_t const edge_id = tri->vw;
if(supports[edge_id] > 0) {
supports[edge_id]--;
if(map_edge_to_bucket(edge_id, thd_ws[tid]) == bucket) {
sbucket_update_edge(&(sbuckets[bucket]), edge_id, supports[edge_id],
ktruss);
} else {
int const edge_bucket = map_edge_to_bucket(edge_id, thd_ws[tid]);
send_thread_edge_msg(edge_id, edge_bucket, thd_ws[tid], 1);
}
++nchanges;
}
} else {
send_thread_edge_msg(tri->vw, bucket_dest, thd_ws[tid], 0);
}
}
} 
gk_stopwctimer(my_timer);
#pragma omp barrier
gk_startwctimer(my_timer);
#pragma omp for schedule(dynamic, 1) nowait
for(int bucket=0; bucket < num_buckets; ++bucket) {
int64_t num_edges = 0;
int64_t * const edges =
get_incoming_edge_bucket(thd_ws, bucket, &num_edges, 0);
for(int64_t e=0; e < num_edges; ++e) {
int64_t const edge_id = edges[e];
if(supports[edge_id] > 0) {
supports[edge_id]--;
if(map_edge_to_bucket(edge_id, thd_ws[tid]) == bucket) {
sbucket_update_edge(&(sbuckets[bucket]), edge_id, supports[edge_id],
ktruss);
} else {
int const edge_bucket = map_edge_to_bucket(edge_id, thd_ws[tid]);
send_thread_edge_msg(edge_id, edge_bucket, thd_ws[tid], 1);
}
++nchanges;
}
}
} 
gk_stopwctimer(my_timer);
#pragma omp barrier
gk_startwctimer(my_timer);
#pragma omp for schedule(dynamic, 1) nowait
for(int bucket=0; bucket < num_buckets; ++bucket) {
int64_t num_edges = 0;
int64_t * const edges =
get_incoming_edge_bucket(thd_ws, bucket, &num_edges, 1);
for(int64_t e=0; e < num_edges; ++e) {
int64_t const edge_id = edges[e];
sbucket_update_edge(&(sbuckets[bucket]), edge_id, supports[edge_id],
ktruss);
}
} 
gk_stopwctimer(my_timer);
update_times[omp_get_thread_num() * TIMER_PADDING] = my_timer;
} 
return nchanges;
}
int64_t kt_msp(params_t *params, vault_t *vault)
{
gk_startwctimer(vault->timer_tcsetup);
vault->ugraph = kt_PreprocessAndExtractUpper(params, vault);
vault->lgraph = kt_TransposeUforJIK(params, vault->ugraph);
int32_t const nvtxs  = vault->ugraph->nvtxs;
ssize_t const * const restrict xadj   = vault->ugraph->xadj;
int32_t const * const restrict adjncy = vault->ugraph->adjncy;
vault->ugraph->iadjwgt = gk_i32malloc(xadj[nvtxs], "adjwgt");
int32_t * const iadjwgt = vault->ugraph->iadjwgt;
par_memset(iadjwgt, 0, xadj[nvtxs] * sizeof(*iadjwgt));
gk_stopwctimer(vault->timer_tcsetup);
gk_startwctimer(vault->timer_esupport);
int64_t ntriangles = kt_ComputeEdgeSupportPar(params, vault);
gk_stopwctimer(vault->timer_esupport);
gk_graph_Free(&(vault->lgraph));
gk_startwctimer(vault->timer_ktsetup);
int64_t nedges = count_nnz(xadj[nvtxs], iadjwgt);
edge_t * edges = gk_malloc((nedges+1) * sizeof(*edges), "edges");
par_memset(edges, 0, (nedges + 1) * sizeof(*edges));
dyn_graph_t * dgraph = p_dgraph_alloc(nvtxs, nedges);
p_init_dgraph(dgraph, vault->ugraph, edges);
gk_stopwctimer(vault->timer_ktsetup);
size_t edge_bytes = (nedges+1) * sizeof(*edges);
printf("EDGES-BYTES: %0.3fGB\n",
(double) edge_bytes / (1024. * 1024. * 1024));
printf("#triangles before peeling: %"PRId64"\n", ntriangles);
ntriangles = 0;
int64_t edges_left = nedges;
dgraph->total_support = count_support(nedges, dgraph->supports);
printf("THREADS: %d\n", omp_get_max_threads());
printf("DYNAMIC_CHUNK: %d\n", DYNAMIC_CHUNK);
printf("KT_BUCKETS_PER_THREAD: %d\n", KT_BUCKETS_PER_THREAD);
printf("MIN_PAR_SIZE: %d\n", MIN_PAR_SIZE);
printf("\n");
thread_ws * * thd_ws = alloc_thread_ws_big(vault->graph);
support_bucket_t * support_buckets = sbucket_alloc(edges, dgraph->supports,
dgraph->nedges, thd_ws);
int64_t * frontier_buf = gk_malloc(dgraph->nedges * sizeof(*frontier_buf),
"frontier_buf");
printf("k: %7d; edges-left: %7"PRId64" (%6.2f%%), total-support: %7"PRId64", time (s): %6.3f\n",
3, edges_left, 100. * (double)edges_left / (double)nedges,
dgraph->total_support,
0.);
double timer_currk;
double timer_frontier;
double timer_updates;
double total_frontier_time;
double total_update_time;
gk_clearwctimer(timer_currk);
gk_clearwctimer(timer_frontier);
gk_clearwctimer(timer_updates);
gk_clearwctimer(total_frontier_time);
gk_clearwctimer(total_update_time);
gk_startwctimer(timer_currk);
gk_startwctimer(vault->timer_ktpeeling);
int32_t ktruss = 4;
while(edges_left > 0) {
gk_startwctimer(timer_frontier);
int64_t const frontier_size = sbucket_get_frontier(support_buckets,
ktruss-3, frontier_buf);
int64_t const delta_edges = p_gen_frontier(dgraph, edges, ktruss,
frontier_buf, frontier_size, thd_ws);
gk_stopwctimer(timer_frontier);
int64_t delta_support;
gk_startwctimer(timer_updates);
if(delta_edges < edges_left) {
delta_support = p_update_supports(dgraph, edges, ktruss,
support_buckets, thd_ws, frontier_size);
} else {
delta_support = dgraph->total_support;
dgraph->total_support = 0;
}
gk_stopwctimer(timer_updates);
#if 0
printf("    frontier:");
thread_time_stats(frontier_times, omp_get_max_threads(), TIMER_PADDING);
printf("    supports:");
thread_time_stats(update_times, omp_get_max_threads(), TIMER_PADDING);
#endif
edges_left -= delta_edges;
dgraph->total_support -= delta_support;
if(edges_left == 0 || (delta_edges == 0 && delta_support == 0)) {
gk_stopwctimer(timer_currk);
printf("k: %7d; edges-left: %7"PRId64" (%6.2f%%), total-support: %7"PRId64", time (s): %6.3f\n",
ktruss, edges_left, 100. * (double)edges_left / (double)nedges,
dgraph->total_support,
timer_currk);
#if 0
printf("  frontier: %6.3fs, updates: %6.3fs\n",
timer_frontier, timer_updates);
#endif
total_frontier_time += timer_frontier;
total_update_time += timer_updates;
++ktruss;
gk_clearwctimer(timer_frontier);
gk_clearwctimer(timer_updates);
gk_clearwctimer(timer_currk);
gk_startwctimer(timer_currk);
}
} 
gk_stopwctimer(vault->timer_ktpeeling);
printf("\n");
#if 0
printf("FRONTIER: %0.3fs UPDATE: %0.3fs\n",
total_frontier_time, total_update_time);
#endif
printf("#triangles after peeling: %"PRId64"\n", ntriangles);
if(params->outfile != NULL) {
#pragma omp parallel for schedule(static)
for(int64_t e=0; e < nedges; ++e) {
dgraph->supports[e] += 2;
}
kt_Sups2KTEdges(params, vault, ktruss-1, dgraph->supports);
}
p_dgraph_free(dgraph);
gk_free((void **)&edges, LTERM);
gk_free((void **)&frontier_buf, LTERM);
free_thread_ws(thd_ws);
sbucket_free(support_buckets);
return ntriangles;
}
