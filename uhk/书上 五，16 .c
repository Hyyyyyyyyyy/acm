#include <stdio.h>
long F(int a);
int main()
{
    int n, i;
    long N, sum = 0;

    scanf("%d", &n);
    if (n <= 0)
        printf("Are you kidding>\n");
    else
    {
        N = F(n);
        printf("N(%d) = %ld\n", n, N);
        for (i = 1; i <= n; i++)
        	sum += F(i);
       	printf("Sum = %ld\n", sum);
    }

    return 0;
}

long F(int a)
{
    long S = 0;
    if (a == 1)
        return 1;
    if (a == 2)
        return 2;
    S = F(a-1) + F(a-2);
    return S;
}
