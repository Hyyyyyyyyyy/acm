#include <stdio.h>
int C(int a, int b);
int A(int a, int b);
int F(int a);
int main()
{
    int n, m, i, j, k, u, temp;
    long long S;
    while(scanf("%d %d %d", &n, &m, &k) != EOF && (n || m || k))
    {
        if(m > n || k > n || (m == n && k > 1) || (k == n && m > 1))
        {
            printf("0\n");
            continue;
        }
        S = 1;
        if(k == 0)
        {
            for(i = 1; i <= n; i++)
                S *= m;
            printf("%lld\n", S);
        }
        else
        {
            for(i = 0; n - i*k > 0; i++)
            {
                S *= C(n-i*k, k);
            }
            if((u = n-k*m) < m)
            {
                temp = u;
                u = m;
                m = temp;
            }
            S *= A(u, m);
            printf("%lld\n", S);
        }
    }
    return 0;
}
int C(int a, int b)
{
    return A(a, b) / F(a-b);
}
int A(int a, int b)
{
    return F(a) / F(b);
}
int F(int a)
{
    int i;
    int S = 1;
    for(i = 1; i <= a; i++)
        S *= i;
    return S;
}