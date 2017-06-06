#include <stdio.h>
int prime(int n);
int Inverse(int n);
int main()
{
    int m, n, i;
    scanf("%d %d", &m, &n);

    for (i = m; i <= n; i++)
        if (prime(i) && prime(Inverse(i)))
            printf("%d\n", i);
    return 0;
}

int prime(int n)
{
    int i;
    for (i = 2; i < n; i++)
        if (n % i == 0)
            break;
    if (i == n)
    	return 1;
    else
    	return 0;
}

int Inverse(int n)
{
    int N = 0;
    while (n > 0)
    {
        N = N * 10 + n % 10;
        n = n / 10;
    }
	return N;
}
