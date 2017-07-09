#include <stdio.h>
#include <tmmintrin.h>

#define MAX_LEN 16

unsigned int *bswap(unsigned int *destination, unsigned int *source, int length) {
    int i;
    __m128i mask = _mm_set_epi8(12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7, 0, 1, 2, 3);
    for (i = 0; i < length; i += 4) {
        _mm_storeu_si128((__m128i *)&destination[i],
        _mm_shuffle_epi8(_mm_loadu_si128((__m128i *)&source[i]), mask));
    }
    return destination;
}

int main (int argc, char **argv)
{
	unsigned int src[MAX_LEN];
	unsigned int dest[MAX_LEN];
	
	bswap(dest, src, MAX_LEN);
	
	for(int i = 0; i < MAX_LEN; ++i)
	{
		printf("src[%d]=%#x\n",i, src[i]);
		printf("dest[%d]=%#x\n",i,dest[i]);
	}	
	return 0;
}
