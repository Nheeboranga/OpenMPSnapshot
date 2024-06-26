#pragma once
#include <chrono>

using std::chrono::microseconds;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;





template <class F>
float measureDuration(F fn, int N=1) {
auto start = high_resolution_clock::now();
for (int i=0; i<N; i++)
fn();
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);
return duration.count()/(N*1000.0f);
}
