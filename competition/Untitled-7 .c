#include <stdio.h>
unsigned long long int F(int p);
int main()
{
    unsigned long long int a, b, c;
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        if(n < m)
        {
            n = n+m;
            m = n - m;
            n = n - m;
        }
        if(m == 0 || m == n)
            printf("%d\n", n);
        else
        {
            a = F(n);
            b = F(m);
            c = F(n-m);
            printf("%d\n", (a/(b*c)));
        }
    }
    return 0;
}

unsigned long long int F(int p)
{
    if(p == 1)
        return 1;
    else
        return F(p-1)*p;
}