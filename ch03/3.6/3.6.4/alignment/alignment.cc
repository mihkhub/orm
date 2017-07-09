#include <string.h>
#include <inttypes.h>
#include <stdio.h>
#include <mm_malloc.h>
#define CACHE_LINE_SIZE 64 
struct foo
{
	uint64_t a __attribute__(( aligned(CACHE_LINE_SIZE) ));
	char b __attribute__(( aligned(CACHE_LINE_SIZE) ));
	int c;
public:
	void * operator new(size_t size)
	{
		return _mm_malloc(size, CACHE_LINE_SIZE);
	}
	void operator delete(void *p)
	{
		return _mm_free(p);
	}
};

int g_var __attribute__(( aligned(CACHE_LINE_SIZE) )) = 0;
int s_var __attribute__(( aligned(CACHE_LINE_SIZE) )) = 0;

//int fun(int __attribute__ ((aligned(CACHE_LINE_SIZE) )) a)
//{
//	return printf("Parameters passed on the stack &a=%p\n", &a);
//}

int main(int argc ,  char **argv)
{
	int stack_var __attribute__ (( aligned(CACHE_LINE_SIZE) ))  = 0;
	printf("CACHE_LINE_SIZE=%u\n",CACHE_LINE_SIZE);
	/* dynamically allocated variables.  */
	foo *fp = new foo;	
	printf("\nDynamically allocated variables: fp=%p\n", fp);
	printf("\nMembers of a data structure: &fp->a=%p\n", &fp->a);
	printf("&fp->b=%p\n", &fp->b);
	printf("&fp->c=%p\n", &fp->c);
	delete fp;
	
	printf("global variable &g_var=%p\n", &g_var);
	printf("staic variable &s_var=%p\n", &s_var);
	printf("stack variable &stack_var=%p\n", &stack_var);
	
	
	return 0;
}
