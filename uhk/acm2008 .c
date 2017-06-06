#include <stdio.h>
int main()
{
    int min, plus, zero;
    int n, i;
    double ar[9999];
    
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        min = 0;
        plus = 0;
        zero = 0;
        for (i = 0; i < n; i++)
            scanf("%lf", &ar[i]);
        for (i = 0; i < n; i++)
        {
            if (ar[i] < 0)
                min++;
            if(ar[i] > 0)
                plus++;
            if (ar[i] == 0)
                zero++;
        }
        printf("%d %d %d\n", min, zero, plus);
    }   
    return 0;
}
