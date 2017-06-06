#include <stdio.h>
#include <math.h>
int main()
{
    int i;
    long long ar[50], sa[50];
    ar[3] = 104;
    ar[4] = 904;
    sa[3] = 16;
    printf("N=3: 104\n");
    for (i = 4; i < 26; i++)
    {
        sa[i] = ar[i-1] - sa[i-1];
        ar[i] = 6 * ar[i-1] - 2 * sa[i-1] + 36 * (pow(2.0, (i-1)) - 2.0) + 2 * (6 * (pow(2.0, (i-1)) - 2.0) + 4 * (pow(2.0, (i-2)) - 1.0));
        printf("N=%d: %lld\n", i, ar[i]);
    }
    return 0;
}
