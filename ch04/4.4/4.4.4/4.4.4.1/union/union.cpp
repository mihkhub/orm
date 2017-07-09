#include <xmmintrin.h>
#include <stdio.h>

union foo 
{
	float f[400];
	__m128 m[100];
};

// If the data in such a class is going to be used with the SIMD, it is perferable to use a union to make this explicit.
class my_m128 
{
	union {
	__m128 m;
	float f[4];
	};
};

int main(int argc, char **argv)
{
	my_m128 m;	
	printf("data in a class &m=%p\n", &m);
	foo f;
	printf("union &f=%p\n",&f);
	return 0;
}
