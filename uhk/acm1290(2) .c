#include <stdio.h>
int main()
{
    int n, i;
    long long int ar[1100];
    while (scanf("%d", &n) != EOF)
    {
        ar[1] = 2;
        ar[2] = 4;
        if (n == 1)
            printf("2\n");
        else if (n == 2)
            printf("4\n");
        else
        {
            for (i = 3; i <= n; i++)
            {
                ar[i] = ar[i-1] + i * (i-1) / 2 + 1;
            }
            printf("%lld\n", ar[i-1]);
        }
    }
    return 0;
}

/*	an = n + 1;
	bn = bn-1 + an-1;	bn = bn-1 + n;
	cn = cn-1 + bn-1;
	Ыљвд
	an = n + 1;
	bn =  n*(n+1)/2 + 1;
	cn =  cn-1 + n*(n-1)/2 + 1;
*/