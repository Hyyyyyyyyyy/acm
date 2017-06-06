#include <stdio.h>
long long int f(long long int a);
int main()
{
    long long int n;

    scanf("%lld", &n);
    printf("%lld\n", f(n));

    return 0;
}

long long int f(long long int a)
{
    long long int ar[1000], T = 1;
    int i = 0, u;
    while (a > 0)
    {
        ar[i] = a % 10;
        a = a / 10;
        i++;
    }
    for (u = 0; u < i; u++)
        ar[u] = (ar[u] == 0) ? 1:ar[u];
    for (u = 0; u < i; u++)
        T *= ar[u];
    return T;
}
