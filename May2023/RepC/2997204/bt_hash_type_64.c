#ifdef HAVE_OPENCL
#include <stdlib.h>
#include <stdio.h>
#include "bt_hash_types.h"
uint64_t *bt_loaded_hashes_64 = NULL;
unsigned int *bt_hash_table_64 = NULL;
inline unsigned int modulo64_31b(uint64_t a, unsigned int N)
{
return (unsigned int)(a % N);
}
inline uint64_t add64(uint64_t a, unsigned int b)
{
return (a + b);
}
void allocate_ht_64(unsigned int num_loaded_hashes, unsigned int verbosity)
{
unsigned int i;
if (bt_memalign_alloc((void **)&bt_hash_table_64, 16, 2 * bt_hash_table_size * sizeof(unsigned int)))
bt_error("Couldn't allocate bt_hash_table_64.");
for (i = 0; i < bt_hash_table_size; i++)
bt_hash_table_64[i] = bt_hash_table_64[i + bt_hash_table_size] = 0;
bt_total_memory_in_bytes += 2 * bt_hash_table_size * sizeof(unsigned int);
if (verbosity > 2) {
fprintf(stdout, "Hash Table Size %Lf %% of Number of Loaded Hashes.\n", ((long double)bt_hash_table_size / (long double)num_loaded_hashes) * 100.00);
fprintf(stdout, "Hash Table Size(in GBs):%Lf\n", ((long double)2.0 * bt_hash_table_size * sizeof(unsigned int)) / ((long double)1024 * 1024 * 1024));
}
}
inline unsigned int calc_ht_idx_64(unsigned int hash_location, unsigned int offset)
{
return  modulo64_31b(add64(bt_loaded_hashes_64[hash_location], offset), bt_hash_table_size);
}
inline unsigned int zero_check_ht_64(unsigned int hash_table_idx)
{
return (bt_hash_table_64[hash_table_idx] || bt_hash_table_64[hash_table_idx + bt_hash_table_size]);
}
inline void assign_ht_64(unsigned int hash_table_idx, unsigned int hash_location)
{
uint64_t hash = bt_loaded_hashes_64[hash_location];
bt_hash_table_64[hash_table_idx] = (unsigned int)(hash & 0xffffffff);
bt_hash_table_64[hash_table_idx + bt_hash_table_size] = (unsigned int)(hash >> 32);
}
inline void assign0_ht_64(unsigned int hash_table_idx)
{
bt_hash_table_64[hash_table_idx] = bt_hash_table_64[hash_table_idx + bt_hash_table_size] = 0;
}
unsigned int get_offset_64(unsigned int hash_table_idx, unsigned int hash_location)
{
unsigned int z = modulo64_31b(bt_loaded_hashes_64[hash_location], bt_hash_table_size);
return (bt_hash_table_size - z + hash_table_idx);
}
int test_tables_64(unsigned int num_loaded_hashes, OFFSET_TABLE_WORD *offset_table, unsigned int offset_table_size, unsigned int shift64_ot_sz, unsigned int shift128_ot_sz, unsigned int verbosity)
{
unsigned char *hash_table_collisions;
unsigned int i, hash_table_idx, error = 1, count = 0;
uint64_t hash;
if (bt_calloc((void **)&hash_table_collisions, bt_hash_table_size, sizeof(unsigned char)))
bt_error("Failed to allocate memory: hash_table_collisions.");
if (verbosity > 1)
fprintf(stdout, "\nTesting Tables...");
#if _OPENMP
#pragma omp parallel private(i, hash_table_idx, hash)
#endif
{
#if _OPENMP
#pragma omp for
#endif
for (i = 0; i < num_loaded_hashes; i++) {
hash = bt_loaded_hashes_64[i];
hash_table_idx =
calc_ht_idx_64(i,
(unsigned int)offset_table[
modulo64_31b(hash,
offset_table_size)]);
#if _OPENMP
#pragma omp atomic
#endif
hash_table_collisions[hash_table_idx]++;
if (error && (bt_hash_table_64[hash_table_idx] != (unsigned int)(hash & 0xffffffff)  ||
bt_hash_table_64[hash_table_idx + bt_hash_table_size] != (unsigned int)(hash >> 32) ||
hash_table_collisions[hash_table_idx] > 1)) {
fprintf(stderr, "Error building tables: Loaded hash idx:%u, No. of collisions:%u\n", i, hash_table_collisions[hash_table_idx]);
error = 0;
}
}
#if _OPENMP
#pragma omp single
#endif
for (hash_table_idx = 0; hash_table_idx < bt_hash_table_size; hash_table_idx++)
if (zero_check_ht_64(hash_table_idx))
count++;
#if _OPENMP
#pragma omp barrier
#endif
}
#define UNUSED(x) (void)(x)
UNUSED(shift128_ot_sz);
UNUSED(shift64_ot_sz);
if (count != num_loaded_hashes) {
error = 0;
fprintf(stderr, "Error!! Tables contains extra or less entries.\n");
return 0;
}
bt_free((void **)&hash_table_collisions);
if (error && verbosity > 1)
fprintf(stdout, "OK\n");
return 1;
}
#define check_equal(p, q) \
(bt_loaded_hashes_64[p] == bt_loaded_hashes_64[q])
#define check_non_zero(p) \
(bt_loaded_hashes_64[p])
#define check_zero(p) \
(bt_loaded_hashes_64[p] == 0)
#define set_zero(p) \
bt_loaded_hashes_64[p] = 0
static void remove_duplicates_final(unsigned int num_loaded_hashes, unsigned int bt_hash_table_size, unsigned int *rehash_list)
{
unsigned int i, **hash_location_list, counter;
#define COLLISION_DTYPE unsigned int
COLLISION_DTYPE *collisions;
typedef struct {
unsigned int store_loc1;
unsigned int store_loc2;
unsigned int idx_hash_loc_list;
COLLISION_DTYPE  collisions;
COLLISION_DTYPE iter;
} hash_table_data;
hash_table_data *hash_table = NULL;
if (bt_malloc((void **)&hash_table, bt_hash_table_size * sizeof(hash_table_data)))
bt_error("Failed to allocate memory: hash_table.");
if (bt_calloc((void **)&collisions, bt_hash_table_size, sizeof(COLLISION_DTYPE)))
bt_error("Failed to allocate memory: collisions.");
for (i = 0; i < num_loaded_hashes; i++) {
unsigned int idx = bt_loaded_hashes_64[rehash_list[i]] % bt_hash_table_size;
collisions[idx]++;
}
counter = 0;
for (i = 0; i < bt_hash_table_size; i++) {
hash_table[i].collisions = collisions[i];
hash_table[i].iter = 0;
hash_table[i].store_loc1 = hash_table[i].store_loc2 =
hash_table[i].idx_hash_loc_list = 0xffffffff;
if (hash_table[i].collisions > 3)
hash_table[i].idx_hash_loc_list = counter++;
}
if (bt_malloc((void **)&hash_location_list, (counter + 1) * sizeof(unsigned int *)))
bt_error("Failed to allocate memory: hash_location_list.");
counter = 0;
for (i = 0; i < bt_hash_table_size; i++)
if (collisions[i] > 3) {
if (bt_malloc((void **)&hash_location_list[counter], (collisions[i] - 1) * sizeof(unsigned int)))
bt_error("Failed to allocate memory: hash_location_list[counter].");
counter++;
}
for (i = 0; i < num_loaded_hashes; i++) {
unsigned int k = rehash_list[i];
unsigned int idx = bt_loaded_hashes_64[k] % bt_hash_table_size ;
if (collisions[idx] == 2) {
if (!hash_table[idx].iter) {
hash_table[idx].iter++;
hash_table[idx].store_loc1 = k;
}
else if (check_equal(hash_table[idx].store_loc1, k))
set_zero(k);
}
if (collisions[idx] == 3) {
if (!hash_table[idx].iter) {
hash_table[idx].iter++;
hash_table[idx].store_loc1 = k;
}
else if (hash_table[idx].iter == 1) {
if (check_equal(hash_table[idx].store_loc1, k))
set_zero(k);
else
hash_table[idx].store_loc2 = k;
}
else if (check_equal(hash_table[idx].store_loc1, k) ||
check_equal(hash_table[idx].store_loc2, k))
set_zero(k);
}
else if (collisions[idx] > 3) {
unsigned int iter = hash_table[idx].iter;
if (!iter)
hash_location_list[hash_table[idx].idx_hash_loc_list][iter++] = k;
else {
unsigned int j;
for (j = 0; j < iter; j++)
if (check_equal(hash_location_list[hash_table[idx].idx_hash_loc_list][j], k)) {
set_zero(k);
break;
}
if (j == iter && iter < (unsigned int)hash_table[idx].collisions - 1)
hash_location_list[hash_table[idx].idx_hash_loc_list][iter++] = k;
}
hash_table[idx].iter = iter;
}
}
#undef COLLISION_DTYPE
for (i = 0; i < counter; i++)
bt_free((void **)&hash_location_list[i]);
bt_free((void **)&hash_location_list);
bt_free((void **)&hash_table);
bt_free((void **)&collisions);
}
unsigned int remove_duplicates_64(unsigned int num_loaded_hashes, unsigned int bt_hash_table_size, unsigned int verbosity)
{
unsigned int i, num_unique_hashes, *rehash_list, counter;
#define COLLISION_DTYPE unsigned int
COLLISION_DTYPE *collisions;
typedef struct {
unsigned int store_loc1;
unsigned int store_loc2;
unsigned int store_loc3;
COLLISION_DTYPE iter;
} hash_table_data;
hash_table_data *hash_table = NULL;
if (verbosity > 1)
fprintf(stdout, "Removing duplicate hashes...");
if (bt_hash_table_size & (bt_hash_table_size - 1)) {
fprintf(stderr, "Duplicate removal hash table size must power of 2.\n");
return 0;
}
if (bt_malloc((void **)&hash_table, bt_hash_table_size * sizeof(hash_table_data)))
bt_error("Failed to allocate memory: hash_table.");
if (bt_calloc((void **)&collisions, bt_hash_table_size, sizeof(COLLISION_DTYPE)))
bt_error("Failed to allocate memory: collisions.");
#if _OPENMP
#pragma omp parallel private(i)
#endif
{
#if _OPENMP
#pragma omp for
#endif
for (i = 0; i < num_loaded_hashes; i++) {
unsigned int idx = bt_loaded_hashes_64[i] & (bt_hash_table_size - 1);
#if _OPENMP
#pragma omp atomic
#endif
collisions[idx]++;
}
counter = 0;
#if _OPENMP
#pragma omp barrier
#endif
#if _OPENMP
#pragma omp for
#endif
for (i = 0; i < bt_hash_table_size; i++) {
hash_table[i].iter = 0;
if (collisions[i] > 4)
#if _OPENMP
#pragma omp atomic
#endif
counter += (collisions[i] - 3);
}
#if _OPENMP
#pragma omp barrier
#pragma omp sections
#endif
{
#if _OPENMP
#pragma omp section
#endif
{
for (i = 0; i < num_loaded_hashes; i++) {
unsigned int idx = bt_loaded_hashes_64[i] & (bt_hash_table_size - 1);
if (collisions[idx] == 2) {
if (!hash_table[idx].iter) {
hash_table[idx].iter++;
hash_table[idx].store_loc1 = i;
}
else if (check_equal(hash_table[idx].store_loc1, i))
set_zero(i);
}
}
}
#if _OPENMP
#pragma omp section
#endif
{
if (bt_malloc((void **)&rehash_list, counter * sizeof(unsigned int)))
bt_error("Failed to allocate memory: rehash_list.");
counter = 0;
for (i = 0; i < num_loaded_hashes; i++) {
unsigned int idx = bt_loaded_hashes_64[i] & (bt_hash_table_size - 1);
if (collisions[idx] == 3) {
if (!hash_table[idx].iter) {
hash_table[idx].iter++;
hash_table[idx].store_loc1 = i;
}
else if (hash_table[idx].iter == 1) {
if (check_equal(hash_table[idx].store_loc1, i))
set_zero(i);
else {
hash_table[idx].iter++;
hash_table[idx].store_loc2 = i;
}
}
else if (check_equal(hash_table[idx].store_loc1, i) ||
check_equal(hash_table[idx].store_loc2, i))
set_zero(i);
}
else if (collisions[idx] >= 4) {
if (!hash_table[idx].iter) {
hash_table[idx].iter++;
hash_table[idx].store_loc1 = i;
}
else if (hash_table[idx].iter == 1) {
if (check_equal(hash_table[idx].store_loc1, i))
set_zero(i);
else {
hash_table[idx].iter++;
hash_table[idx].store_loc2 = i;
}
}
else if (hash_table[idx].iter == 2) {
if (check_equal(hash_table[idx].store_loc1, i) ||
check_equal(hash_table[idx].store_loc2, i))
set_zero(i);
else {
hash_table[idx].iter++;
hash_table[idx].store_loc3 = i;
}
}
else if (hash_table[idx].iter >= 3) {
if (check_equal(hash_table[idx].store_loc1, i) ||
check_equal(hash_table[idx].store_loc2, i) ||
check_equal(hash_table[idx].store_loc3, i))
set_zero(i);
else {
if (collisions[idx] > 4)
rehash_list[counter++] = i;
}
}
}
}
if (counter)
remove_duplicates_final(counter, counter + (counter >> 1), rehash_list);
bt_free((void **)&rehash_list);
}
}
}
#if 0
{	unsigned int col1 = 0, col2 = 0, col3 = 0, col4 = 0, col5a = 0;
for (i = 0; i < bt_hash_table_size; i++) {
if (collisions[i] == 1)
col1++;
else if (collisions[i] == 2)
col2++;
else if (collisions[i] == 3)
col3++;
else if (collisions[i] == 4)
col4++;
else if (collisions[i] > 4)
col5a += collisions[i];
}
col2 *= 2;
col3 *= 3;
col4 *= 4;
fprintf(stderr, "Statistics:%Lf %Lf %Lf %Lf %Lf\n", (long double)col1 / (long double)num_loaded_hashes,
(long double)col2 / (long double)num_loaded_hashes, (long double)col3 / (long double)num_loaded_hashes,
(long double)col4 / (long double)num_loaded_hashes, (long double)col5a / (long double)num_loaded_hashes);
}
#endif
num_unique_hashes = 0;
for (i = num_loaded_hashes - 1; (int)i >= 0; i--)
if (check_non_zero(i)) {
num_unique_hashes = i;
break;
}
for (i = 0; i <= num_unique_hashes; i++)
if (check_zero(i)) {
unsigned int j;
bt_loaded_hashes_64[i] = bt_loaded_hashes_64[num_unique_hashes];
set_zero(num_unique_hashes);
num_unique_hashes--;
for (j = num_unique_hashes; (int)j >= 0; j--)
if (check_non_zero(j)) {
num_unique_hashes = j;
break;
}
}
#undef COLLISION_DTYPE
bt_free((void **)&collisions);
bt_free((void **)&hash_table);
if (verbosity > 1)
fprintf(stdout, "Done\n");
return (num_unique_hashes + 1);
}
#endif
