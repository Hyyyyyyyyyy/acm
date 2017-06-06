#include <stdio.h>
long long int F(long long int a);
int main()
{
    long long int m;
    scanf("%lld", &m);
	if(F(m) == 1)
		printf("yes");
	else
		printf("no");
    return 0;
}

long long int F(long long int a)
{
	long long int q, i = 0;
	q = a;
    while (q > 0)
    {
        i = q % 10 + i * 10;
        q = q / 10;
    }
    if (i == a)
        return 1;
    else
    	return 0;
}
