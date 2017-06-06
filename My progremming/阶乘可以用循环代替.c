#include <stdio.h>
int main()
{
	int i, n = 1;
	long T;
	do
	{
		T = 1;
		for (i = n; i > 1; i--)
			T *= i;
		n++;
	}while((1.0 / T) >= 1.0e-6);
	printf("T = %ld\n", T);
	return 0;
}
