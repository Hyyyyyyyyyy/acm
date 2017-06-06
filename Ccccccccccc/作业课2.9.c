#include <stdio.h>
#include <math.h>
int gcd(int a, int b)
{
    int temp;
    while(b)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    int i, j, k, n, m;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        printf("%d\n", n * m / gcd(n, m));
    }
    return 0;
}