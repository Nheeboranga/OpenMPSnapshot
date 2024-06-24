#ifdef EIGEN_WARNINGS_DISABLED_2
#  undef EIGEN_WARNINGS_DISABLED_2

#elif defined(EIGEN_WARNINGS_DISABLED)
#undef EIGEN_WARNINGS_DISABLED

#ifndef EIGEN_PERMANENTLY_DISABLE_STUPID_WARNINGS
#ifdef _MSC_VER
#pragma warning( pop )
#elif defined __INTEL_COMPILER
#pragma warning pop
#elif defined __clang__
#pragma clang diagnostic pop
#elif defined __GNUC__  &&  (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
#pragma GCC diagnostic pop
#endif

#if defined __NVCC__
#endif

#endif

#endif 
