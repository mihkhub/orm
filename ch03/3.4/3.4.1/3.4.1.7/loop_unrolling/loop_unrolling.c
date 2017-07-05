int bunrolling(int* a,int  len)
{
	int sum;
	for(int i=0; i < len; i++)
	{
		sum += a[i];
	}
	return sum;
}
int aunrolling(int* a, int len)
{
	int sum;
	for(int i=0; i < len; i+=4)
	{
		sum += a[i+0];
		sum += a[i+1];
		sum += a[i+2];
		sum += a[i+3];
	}
	return sum;
}
int main(int argc, char **argv)
{
	
	return 0;
}
