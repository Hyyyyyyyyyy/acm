#include <stdio.h>
int main()
{
    int n, i;
    unsigned long long sa[2000], ar[2000];
    while (scanf("%d", &n) != EOF)
    {
        if(n == 1)
            printf("1\n");
        else if (n == 2)
            printf("2\n");
        else
        {
            ar[1] = 1;
            ar[2] = 2;
            ar[3] = 4;
            sa[1] = 0;
            sa[2] = 1;
            sa[3] = 2;
            for (i = 4; i <= n; i++)
            {
                sa[i] = sa[i-1] + ar[i-3];
                ar[i] = ar[i-1] + sa[i-1] + ar[i-3];
            }
            printf("%llu\n", ar[i-1]);
        }

    }
    return 0;
}




#include <stdio.h>
int main()
{
    int n, i, u, k;
    unsigned long long sa[2000], ar[2000];
	char Z[2000];
    while (scanf("%d", &n) != EOF)
    {
        if(n == 1)
            printf("1\n");
        else if (n == 2)
            printf("2\n");
        else
        {
            ar[1] = 1;
            ar[2] = 2;
            ar[3] = 4;
            sa[1] = 0;
            sa[2] = 1;
            sa[3] = 2;
            for (i = 4; i <= n; i++)
            {
                sa[i] = sa[i-1] + ar[i-3];
                ar[i] = ar[i-1] + sa[i-1] + ar[i-3];
            }
            for (u = 0;;u++)
            {
          		if (ar[i-1] == 0)
          			break;
     			Z[u] = ar[i-1] % 10;
     			ar[i-1] = ar[i-1] / 10;
            }
            for (k = 0; k < u; k++)
            	printf("%c", Z[k]);
        }

    }
    return 0;
}



#include <stdio.h>
int main()
{
    int n, i, u, k;
    unsigned long long sa[200][2000], ar[200][2000];
    while (scanf("%d", &n) != EOF)
    {
        if(n == 1)
            printf("1\n");
        else if (n == 2)
            printf("2\n");
        else
        {
            ar[1] = 1;
            ar[2] = 2;
            ar[3] = 4;
            sa[1] = 0;
            sa[2] = 1;
            sa[3] = 2;
            u = 0;
            i = 4;
            for (; i <= n; i++)
            {
                sa[u][i] = sa[u][i-1] + ar[u][i-3];
                ar[u][i] = ar[u][i-1] + sa[u][i-1] + ar[u][i-3];
                if (ar[u][i] > 1000000)
                {
                    n = n - i - 1;
                    u++;
                    sa[u][0] = (sa[u-1][i] + ar[u-1][i-2]) % 1000000;
                    ar[u][0] = (ar[u-1][i] + sa[u-1][i] + ar[u-1][i-2]) % 1000000;
                    sa[u][1] = sa[u][0] + ar[u-1][i-1];
                    ar[u][1] = ar[u][0] + sa[u][0] + ar[u-1][i-1];
                    sa[u][2] = sa[u][1] + ar[u-1][i];
                    ar[u][2] = ar[u][1] + sa[u][1] + ar[u-1][i];
                    sa[u][3] = sa[u][2] + ar[u][0];
                    ar[u][3] = ar[u][2] + sa[u][2] + ar[u][0];
                    i = 4;
                }
            }
            for (k = 0; k < u; k++)
            {

            }
                
            
        }

    }
    return 0;
}
