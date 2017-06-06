#include <stdio.h>
int main()
{
    int i, j, k, u, n, m, a, b, ar[110], sum, S;
    while(scanf("%d", &n) != EOF)
    {
        sum = 0;
        S = 0;
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &ar[m]);
            sum += ar[m];
        }
        sum /= n;
        for(i = 1; i <= n  ; i++)
        {
            if(ar[i] > sum)
            {
                ar[i+1] += ar[i] - sum;
                S += ar[i] - sum;
            }
            if(ar[i] < sum)
            {
                ar[i+1] -= sum - ar[i];
                S += sum + ar[i];
            }
        }
        printf("%d\n", S);
    }
    return 0;
}