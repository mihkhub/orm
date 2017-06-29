#include <xmmintrin.h>
#include <stdio.h>

/* Alignment by using a union structure */
union 
{
	float f[400];
	__m128 m[100];
} buf;

int main(int argc, char **argv)
{
	/* GCC aligned()  */
	float buffer[400] __attribute__(( aligned(16) ));
	__m128 m[3];
	return 0;
}



