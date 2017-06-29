/*
 * C Algorithm for 64-bit Data Alignment
 */
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define NUM_ELEMENTS 32

int main(int argc, char **argv)
{
	/* Make newp a pointer to a 64-bit aligned array of NUM_ELEMENTS 64-bit elements. */
	double *p, *newp;
	p = (double *) malloc(sizeof(double)*(NUM_ELEMENTS+1));
	printf("p=%p\n", p);
	newp = (double *)((uint64_t)(p +7) & (uint64_t)(~0x7));
	printf("newp=%p\n", newp);
	return 0;
}
