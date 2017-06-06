#include <stdio.h>
//int F(int a);
int main()
{
    int n, m, i, ar[99];
    while (scanf("%d", &n) != EOF)
    {
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &m);
            if ((m-1) == 1)
                printf("1\n");
            else if ((m-1) == 2)
                printf("2\n");
            else
            {
                ar[0] = 1;
                ar[1] = 2;
                for (i = 2; i < m-1; i++)
                {
                    ar[i] = ar[i-1] + ar[i-2];
                }
                printf("%d\n", ar[m-2]);

            }
        }
    }
    return 0;
}

/*int F(int a)
{
	int S;
    if (a == 1)
        return 1;
    else if (a == 2)
        return 2;
    else
    {
        S = F(a-1) + F(a-2);
        return S;
    }
}*/
