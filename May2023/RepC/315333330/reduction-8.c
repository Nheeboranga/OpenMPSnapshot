struct A { int t; };
struct B { char t; };
struct C { unsigned long long t; };
struct D { long t; };
void
add (struct B *x, struct B *y)
{
x->t += y->t;
}
void
zero (struct B *x)
{
x->t = 0;
}
void
orit (struct C *x, struct C *y)
{
y->t |= x->t;
}
#pragma omp declare reduction(+:struct A:omp_out.t += omp_in.t)
#pragma omp declare reduction(+:struct B:add (&omp_out, &omp_in)) initializer(zero (&omp_priv))
#pragma omp declare reduction(*:struct A:omp_out.t *= omp_in.t) initializer(omp_priv = { 1 })
#pragma omp declare reduction(|:struct C:orit (&omp_in, &omp_out))
#pragma omp declare reduction(&:struct D:omp_out.t = omp_out.t & omp_in.t) initializer(omp_priv = { ~0L })
#pragma omp declare reduction(maxb:short:omp_out = omp_in > omp_out ? omp_in : omp_out) initializer(omp_priv = -6)
struct B z[10];
__attribute__((noinline, noclone)) void
foo (struct A (*x)[3][2], struct A *y, struct D w[1][2])
{
struct C a[9] = {};
short b[5] = {};
int i;
#pragma omp parallel for reduction(+:x[0:2][:][0:2], z[:4]) reduction(*:y[:3]) reduction(|:a[:4]) reduction(&:w[0:1][:2]) reduction(maxb:b)
for (i = 0; i < 128; i++)
{
x[i / 64][i % 3][(i / 4) & 1].t += i;
if ((i & 15) == 1)
y[0].t *= 3;
if ((i & 31) == 2)
y[1].t *= 7;
if ((i & 63) == 3)
y[2].t *= 17;
z[i / 32].t += (i & 3);
if (i < 4)
z[i].t += i;
a[i / 32].t |= 1ULL << (i & 30);
w[0][i & 1].t &= ~(1L << (i / 17 * 3));
if ((i % 79) > b[0])
b[0] = i % 79;
if ((i % 13) > b[1])
b[1] = i % 13;
if ((i % 23) > b[2])
b[2] = i % 23;
if ((i % 85) > b[3])
b[3] = i % 85;
if ((i % 192) > b[4])
b[4] = i % 192;
}
for (i = 0; i < 9; i++)
if (a[i].t != (i < 4 ? 0x55555555ULL : 0))
__builtin_abort ();
if (b[0] != 78 || b[1] != 12 || b[2] != 22 || b[3] != 84 || b[4] != 127)
__builtin_abort ();
}
int
main ()
{
struct A a[4][3][2] = {};
static int a2[4][3][2] = {{{ 0, 0 }, { 0, 0 }, { 0, 0 }},
{{ 312, 381 }, { 295, 356 }, { 337, 335 }},
{{ 1041, 975 }, { 1016, 1085 }, { 935, 1060 }},
{{ 0, 0 }, { 0, 0 }, { 0, 0 }}};
struct A y[5] = { { 0 }, { 1 }, { 1 }, { 1 }, { 0 } };
int y2[5] = { 0, 6561, 2401, 289, 0 };
char z2[10] = { 48, 49, 50, 51, 0, 0, 0, 0, 0, 0 };
struct D w[1][2] = { { { ~0L }, { ~0L } } };
foo (&a[1], y + 1, w);
int i, j, k;
for (i = 0; i < 4; i++)
for (j = 0; j < 3; j++)
for (k = 0; k < 2; k++)
if (a[i][j][k].t != a2[i][j][k])
__builtin_abort ();
for (i = 0; i < 5; i++)
if (y[i].t != y2[i])
__builtin_abort ();
for (i = 0; i < 10; i++)
if (z[i].t != z2[i])
__builtin_abort ();
if (w[0][0].t != ~0x249249L || w[0][1].t != ~0x249249L)
__builtin_abort ();
return 0;
}
