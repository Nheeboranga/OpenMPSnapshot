#pragma once



#include <celero/Celero.h>

#include "bench_utils.hpp"
#include "bnmf_algs.hpp"
#include <fstream>
#include <iostream>

namespace nmf_bench_vars {
size_t r = 15;
double beta;
long x = 100;
long y = 100;
double beg = 0;
double scale = 10;
size_t max_iter = 1000;
} 



BASELINE(nmf, IS_100x100, 0, 1) {
using namespace bnmf_algs;
using namespace benchmark;
using namespace nmf_bench_vars;

x = 100, y = 100;
beta = 0;

matrixd X = make_matrix(x, y, beg, scale);
celero::DoNotOptimizeAway(nmf::nmf(X, r, beta, max_iter));
}

BENCHMARK(nmf, KL_100x100, 0, 1) {
using namespace bnmf_algs;
using namespace benchmark;
using namespace nmf_bench_vars;

x = 100, y = 100;
beta = 1;

matrixd X = make_matrix(x, y, beg, scale);
celero::DoNotOptimizeAway(nmf::nmf(X, r, beta, max_iter));
}

BENCHMARK(nmf, EUC_100x100, 0, 1) {
using namespace bnmf_algs;
using namespace benchmark;
using namespace nmf_bench_vars;

x = 100, y = 100;
beta = 2;

matrixd X = make_matrix(x, y, beg, scale);
celero::DoNotOptimizeAway(nmf::nmf(X, r, beta, max_iter));
}



BASELINE(nmf, IS_200x100, 0, 1) {
using namespace bnmf_algs;
using namespace benchmark;
using namespace nmf_bench_vars;

x = 200, y = 100;
beta = 0;

matrixd X = make_matrix(x, y, beg, scale);
celero::DoNotOptimizeAway(nmf::nmf(X, r, beta, max_iter));
}

BENCHMARK(nmf, KL_200x100, 0, 1) {
using namespace bnmf_algs;
using namespace benchmark;
using namespace nmf_bench_vars;

x = 200, y = 100;
beta = 1;

matrixd X = make_matrix(x, y, beg, scale);
celero::DoNotOptimizeAway(nmf::nmf(X, r, beta, max_iter));
}

BENCHMARK(nmf, EUC_200x100, 0, 1) {
using namespace bnmf_algs;
using namespace benchmark;
using namespace nmf_bench_vars;

x = 200, y = 100;
beta = 2;

matrixd X = make_matrix(x, y, beg, scale);
celero::DoNotOptimizeAway(nmf::nmf(X, r, beta, max_iter));
}



BASELINE(nmf, IS_300x100, 0, 1) {
using namespace bnmf_algs;
using namespace benchmark;
using namespace nmf_bench_vars;

x = 300, y = 100;
beta = 0;

matrixd X = make_matrix(x, y, beg, scale);
celero::DoNotOptimizeAway(nmf::nmf(X, r, beta, max_iter));
}

BENCHMARK(nmf, KL_300x100, 0, 1) {
using namespace bnmf_algs;
using namespace benchmark;
using namespace nmf_bench_vars;

x = 300, y = 100;
beta = 1;

matrixd X = make_matrix(x, y, beg, scale);
celero::DoNotOptimizeAway(nmf::nmf(X, r, beta, max_iter));
}

BENCHMARK(nmf, EUC_300x100, 0, 1) {
using namespace bnmf_algs;
using namespace benchmark;
using namespace nmf_bench_vars;

x = 300, y = 100;
beta = 2;

matrixd X = make_matrix(x, y, beg, scale);
celero::DoNotOptimizeAway(nmf::nmf(X, r, beta, max_iter));
}



BASELINE(nmf, IS_400x100, 0, 1) {
using namespace bnmf_algs;
using namespace benchmark;
using namespace nmf_bench_vars;

x = 400, y = 100;
beta = 0;

matrixd X = make_matrix(x, y, beg, scale);
celero::DoNotOptimizeAway(nmf::nmf(X, r, beta, max_iter));
}

BENCHMARK(nmf, KL_400x100, 0, 1) {
using namespace bnmf_algs;
using namespace benchmark;
using namespace nmf_bench_vars;

x = 400, y = 100;
beta = 1;

matrixd X = make_matrix(x, y, beg, scale);
celero::DoNotOptimizeAway(nmf::nmf(X, r, beta, max_iter));
}

BENCHMARK(nmf, EUC_400x100, 0, 1) {
using namespace bnmf_algs;
using namespace benchmark;
using namespace nmf_bench_vars;

x = 400, y = 100;
beta = 2;

matrixd X = make_matrix(x, y, beg, scale);
celero::DoNotOptimizeAway(nmf::nmf(X, r, beta, max_iter));
}
