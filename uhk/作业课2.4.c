#include <stdio.h>
#include <math.h>
int n, m;
int f(int a, int b)
{
    return (n * b + m * a) % 7;
}
int main()
{
    int i, j, k, a, b, temp, ar[1000];
    while(scanf("%d %d %d", &n, &m, &k) != EOF && (n || m || k))
    {
        a = 1;
        b = 1;
        if(k == 1)
        {
            printf("1\n");
            continue;
        }
        if(k == 2)
        {
              printf("1\n");
              continue;
        }
        for(i = 3; i <= 51; i++)
        {
            temp = f(a, b);
            a = b;
            b = temp;
            ar[i] = temp;
        }
        if(k <= 51)
            printf("%d\n", ar[k]);
           else
            printf("%d\n", ar[(k-51) % 49 + 2]);
    }
    return 0;
}