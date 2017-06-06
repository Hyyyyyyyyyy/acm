#include <stdio.h>
int main()
{
    int a, n, m, p;
    m = 0;

    printf("Please enter an n:\n");
    scanf("%d", &n);
    p = n;
    while(p > 0)
    {
        a = p % 10;
        p = p - a;
        m = a + m * 10;
        p = p / 10;
    }
    if (m == n)
    printf("Yes, this is a symmetrical number!\n");
    else
    printf("No, this is not a symmetrical number.\n");

    return 0;
}
