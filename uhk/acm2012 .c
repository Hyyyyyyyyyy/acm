#include <stdio.h>
int main()
{
    int x, y, n, S, doudou, i;
    while (scanf("%d %d", &x, &y) !=EOF)
    {
        if (x == 0 && y == 0)
            break;
        S = 0;
        doudou = 1;
        for (n = x; n <= y; n++)
        {
            S = pow(n, 2.0) + n + 41;
            for (i = 2; (i * i) <= S; i++)
                if (S % i == 0)
                {
                    doudou = 0;
                    break;
                }
            if (doudou == 0)
                break;
        }
        if (doudou)
            printf("OK\n");
        if (doudou == 0)
            printf("Sorry\n");
    }
    return 0;
}
