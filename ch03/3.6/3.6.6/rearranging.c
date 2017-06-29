struct unpacked /* Fits in 20 bytes due to padding */ 
{
	int a;
	char b;
	int c;
	char d;
	int e;
};

struct packed  /* Fits in 16 bytes */
{
	int a;
	int c;
	int e;
	char b;
	char d;
};

int main(int argc, char **argv)
{
	struct unpacked un;
	struct packed p;
	return 0;
}
