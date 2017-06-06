#include <stdio.h>
long int F(int n);
int main()
{
    int a;
    long sum = 0;
    for (a = 1; a <= 10; a++)
        sum += F(a);
    printf("sum = %ld\n", sum);

    return 0;
}

long int F(int n)
{
    int i;
    long T = 1;
    for (i = 1; i <= n; i++)
        T *= i;
    return T;
}
