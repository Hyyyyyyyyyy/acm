#include <stdio.h>
int main()
{
    int s, d, n;

    while (scanf("%d", &n) != EOF)
    {
        s = 1;
        d = 1;
        while (d < n)
        {
            s = (s + 1) * 2;
            d = d + 1;
        }
        printf("%d\n", s);
    }
    return 0;
}
