
#define Num 16384
int main(int argc, char **argv)
{
	float v[Num];
	const int strip_size = 4;
	long long int sum;
	for(int i =0; i < Num;i += strip_size)
	{
		sum = v[i] + v[i+1] + v[i+2] + v[i+3];	
	}
	return 0;
}
