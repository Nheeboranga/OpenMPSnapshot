#pragma GCC target("htm")
void p1(void)
{
#ifndef __HTM__
#error __HTM__ is not defined
#endif
__builtin_tend ();
}
#pragma GCC reset_options
#pragma GCC target("no-htm")
void p0(void)
{
#ifdef __HTM__
#error __HTM__ is defined
#endif
__builtin_tend (); 
}
#pragma GCC reset_options
__attribute__ ((target("htm")))
void a1(void)
{
#ifdef __HTM__
#error __HTM__ is defined
#endif
__builtin_tend ();
}
__attribute__ ((target("no-htm")))
void a0(void)
{
#ifdef __HTM__
#error __HTM__ is defined
#endif
__builtin_tend (); 
}
void htmd(void)
{
#ifdef __HTM__
#error __HTM__ is defined
#endif
__builtin_tend (); 
}
