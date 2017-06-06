#include <stdio.h>
int main()
{
    int n, i, S, max, min, ar[9999];
    while (scanf("%d", &n) != EOF)
    {
    	S = 0;
    	max = 0;
    	min = 100;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &ar[i]);
            max = (max > ar[i]) ? max:ar[i];
            min = (min < ar[i]) ? min:ar[i];
        }
        for (i = 0; i < n; i++)
            S += ar[i];
        printf("%.2lf\n", (double)((S - max - min)) / (n - 2));
    }
    return 0;
}
