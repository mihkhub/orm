#include <xmmintrin.h>
#include <stdio.h>

void add(float *a, float *b, float *c)
{
	__m128 t0, t1;
	t0 =  _mm_load_ps(a);
	t1 = _mm_load_ps(b);
	t0 = _mm_add_ps(t0, t1);
	_mm_store_ps(c,t0);
}

int main(int argc, char **argv)
{
	float a[16];
	float b[16];
	float c[16];
	a[0] = 1.3;
	b[0] = 3.14;
	add(a, b, c);
	printf("%f + %f = %f\n",a[0], b[0], c[0]);
	return 0;
}

