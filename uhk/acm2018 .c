#include <stdio.h>
int main()
{
    int n, i, ar[9999], S;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        ar[0] = 1;
        ar[1] = 2;
        ar[2] = 3;
        ar[3] = 4;
        if (n == 1)
            printf("%d\n", ar[0]);
        else if (n == 2)
            printf("%d\n", ar[1]);
        else if (n == 3)
            printf("%d\n", ar[2]);
        else if (n == 4)
           printf("%d\n", ar[3]);
        else 
        {
            S = 0;
            for (i = 4; i < n; i++)
                ar[i] = ar[i-1] + ar[i-3];
            printf("%d\n", ar[n-1]);
        }
    }
    return 0;
}
