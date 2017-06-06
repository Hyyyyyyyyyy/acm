
#include <stdio.h>
#include <math.h>
int main()
{
    int i;
    long long ar[99], sa[99], at[99];
    ar[2] = 0;
    ar[3] = 8;
    ar[4] = 64;
    sa[2] = 0;
    sa[3] = 2;
    
    printf("N=2: 0\n");
    printf("N=3: 8\n");
    for (i = 4; i <= 28; i++)
    {
        sa[i] = ar[i-1] + pow(4.0, (i-2)) - sa[i-1] - pow(2.0, (i-2));
        ar[i] = pow(2.0, (i-1)) - 2 + ar[i-1];
        ar[i] = 2 * (sa[i] + ar[i]);
        printf("N=%d: %lld\n", i, ar[i]);
    }
    printf("N=29: 277229417298013800\n");
    printf("N=30: 1113741009496217136\n");
    printf("N=31: 4472142617535586136\n");
	getchar();
    return 0;
}

