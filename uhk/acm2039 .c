#include <stdio.h>
int main()
{
    int n, m, a, b, c;

    while (scanf("%d", &n) != EOF)
    {
        for (m = 1; m <= n; m++)
        {
            scanf("%d %d %d", &a, &b, &c);
            if(a > b)
            {
                a = a + b;
                b = a - b;
                a = a -b;
            }
            if(c < b)
            {
                b = c + b;
                c = b - c;
                b = b - c;
            }
            if(a > b)
            {
                a = a + b;
                b = a - b;
                a = a - b;
            }
            if((a+b) > c && (c-b) < a)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
