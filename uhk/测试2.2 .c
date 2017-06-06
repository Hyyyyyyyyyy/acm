#include <stdio.h>
int F(long int , long int);
int main()
{
    long int n, m, max, min;
	
	scanf("%d %d", &n, &m);
    max = (n > m) ? n:m;
    min = (n < m) ? n:m;
    printf("%ld", F(max,min));
    return 0;
}

int F(long int a, long int b)
{
    if ((a % b) == 0)
        return b;
    else
	    return F(b, (a % b));
}
