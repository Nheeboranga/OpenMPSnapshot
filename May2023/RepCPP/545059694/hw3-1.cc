#include <stdio.h>
#include <stdlib.h>

const int INF = ((1 << 30) - 1);
const int V = 50010;
void input(char* inFileName);
void output(char* outFileName);

void block_FW(int B);
int ceil(int a, int b);
void cal(int B, int Round, int block_start_x, int block_start_y, int block_width, int block_height);

int n, m;
static int Dist[V][V];

int main(int argc, char* argv[]) {
input(argv[1]);
int B = 512;
block_FW(B);
output(argv[2]);
return 0;
}

void input(char* infile) {
FILE* file = fopen(infile, "rb");
fread(&n, sizeof(int), 1, file);
fread(&m, sizeof(int), 1, file);

for (int i = 0; i < n; ++i) {
for (int j = 0; j < n; ++j) {
if (i == j) {
Dist[i][j] = 0;
} else {
Dist[i][j] = INF;
}
}
}

int pair[3];
for (int i = 0; i < m; ++i) {
fread(pair, sizeof(int), 3, file);
Dist[pair[0]][pair[1]] = pair[2];
}
fclose(file);
}

void output(char* outFileName) {
FILE* outfile = fopen(outFileName, "w");
for (int i = 0; i < n; ++i) {
for (int j = 0; j < n; ++j) {
if (Dist[i][j] >= INF) Dist[i][j] = INF;
}
fwrite(Dist[i], sizeof(int), n, outfile);
}
fclose(outfile);
}

int ceil(int a, int b) { return (a + b - 1) / b; }

void block_FW(int B) {
int round = ceil(n, B);
for (int r = 0; r < round; ++r) {
fflush(stdout);

cal(B, r, r, r, 1, 1);


cal(B, r, r, 0, 1, r);
cal(B, r, r, r + 1, 1, round - r - 1);
cal(B, r, 0, r, r, 1);
cal(B, r, r + 1, r, round - r - 1, 1);


cal(B, r, 0, 0, r, r);
cal(B, r, 0, r + 1, r, round - r - 1);
cal(B, r, r + 1, 0, round - r - 1, r);
cal(B, r, r + 1, r + 1, round - r - 1, round - r - 1);
}
}

void cal(
int B, int Round, int block_start_x, int block_start_y, int block_width, int block_height) {
int block_end_x = block_start_x + block_width;
int block_end_y = block_start_y + block_height;
int end_k = (Round + 1) * B > n ? n : (Round + 1) * B;

for (int b_i = block_start_x; b_i < block_end_x; ++b_i) {
for (int b_j = block_start_y; b_j < block_end_y; ++b_j) {
int block_internal_start_x = b_i * B;
int block_internal_end_x = (b_i + 1) * B;
int block_internal_start_y = b_j * B;
int block_internal_end_y = (b_j + 1) * B;
if (block_internal_end_x > n) block_internal_end_x = n;
if (block_internal_end_y > n) block_internal_end_y = n;

for (int k = Round * B; k < end_k; ++k) {
#pragma omp parallel for schedule(dynamic, 1)
for (int i = block_internal_start_x; i < block_internal_end_x; ++i) {
for (int j = block_internal_start_y; j < block_internal_end_y; ++j) {
if (Dist[i][k] + Dist[k][j] < Dist[i][j]) {
Dist[i][j] = Dist[i][k] + Dist[k][j];
}
}
}
}
}
}
}