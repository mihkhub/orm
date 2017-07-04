#include <xmmintrin.h>
#include <stdio.h>
#include "util.h"
#include <mm_malloc.h>

void add(float *a, float *b, float *c)
{
	int i;
	for (i = 0; i < 4; i++) 
	{
		c[i] = a[i] + b[i];
	}
}

void addv(float *a, float *b, float *c)
{
	__m128 t0, t1;
	t0 =  _mm_load_ps(a);
	t1 = _mm_load_ps(b);
	t0 = _mm_add_ps(t0, t1);
	_mm_store_ps(c,t0);
}

int main(int argc, char **argv)
{
	int count=1000, samples;
    	int raw_counts = 0;
    	timing_t start, end, *stats;
	float a[16];
	float b[16];
	float c[16];
	a[0] = 1.3;
	b[0] = 3.14;
	
	samples = 0;
    	stats = _mm_malloc(count * sizeof(timing_t), 8);
    	while (samples < count)
    	{
        timing_start(start);

	addv(a, b, c);
	timing_end(end);
        stats[samples++] = end-start;
	}
	printf("addv\n");
	timing_print(stats, count, raw_counts);

	samples = 0;	
    	while (samples < count)
    	{
        timing_start(start);

	add(a, b, c);
	timing_end(end);
        stats[samples++] = end-start;
	}
	printf("add\n");
	timing_print(stats, count, raw_counts);
	printf("%f + %f = %f\n",a[0], b[0], c[0]);
	_mm_free(stats);
	return 0;
}

