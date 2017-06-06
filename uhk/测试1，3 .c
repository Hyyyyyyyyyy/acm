#include <stdio.h>
int F(int n);
int main()
{
    int a, judge, m, max = 6;
    
    scanf("%d", &m);
    for (a = 1; a <= m; a++)
	{
		    judge = F(a);
		    if (judge == 1)
                max = (max > a) ? max:a;
    }
    printf("%d\n", max);
    return 0;
}

int F(int n)
{
    int sum = 0, i;

    for (i = 1; i < n; i++)
        sum = (n % i == 0) ? (sum + i):sum;
    if (sum == n)
        return 1;
    return 0;
}
