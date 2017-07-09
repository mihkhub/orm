#include <stdio.h>
#define BUFF_SIZE  16384

int main(int argc, char **argv)
{
	int buff[BUFF_SIZE];
	int sum = 0;
	int i;	
	for (i =0; i < BUFF_SIZE; i++)
	{
		sum += buff[i];
	}

	printf("sum = %d\n", sum);
	return 0;
}
