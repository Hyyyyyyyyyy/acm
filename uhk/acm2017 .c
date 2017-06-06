#include <stdio.h>
#include <ctype.h>
int main()
{
    int n, i, p, num;
    char ar[9999];
    while (scanf("%d", &n) != EOF)
    {
        for (p = 1; p <= n; p++)
        {
            num = 0;
            for (i = 0; i < 9999; i++)
            {
                scanf("%c", &ar[i]);
                if (isdigit(ar[i]))
                    num++;
                if (i > 0 && ar[i] == '\n')
                    break;
            }
            printf("%d\n", num);
        }
    }
    return 0;
}
