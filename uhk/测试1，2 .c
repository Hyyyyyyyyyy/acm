#include <stdio.h>
int main()
{
    int min = 0, plus = 0, zero = 0;
    int n, i;
    
    scanf("%d", &n);
    double ar[n];
    
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
    printf("%d,%d,%d\n", min, plus, zero);

    return 0;
}
