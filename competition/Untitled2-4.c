#include <stdio.h>
#include <math.h>
int main()
{
    int n, m, i, j, key, mid, S, ar[100005];
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d", &ar[i]);
            key = ar[i];
            j = i - 1;
            while (j > 0 && key < ar[j])
            {
                ar[j+1] = ar[j];
                j--;
            }
            ar[j+1] = key;
        }
        mid = (ar[0] + ar[i-1]) / 2;
        S = 0;
        for (i = 0, u = n-1; i < (n/2), u >= (n/2) ; i++, u--)
            S = S + abs(ar[u] - mid) + abs(ar[i] - mid);
        printf("%d\n", S);
    }
    return 0;
}
