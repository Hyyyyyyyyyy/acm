#include <stdio.h>
#include <math.h>
#define LEN 10
void paixu(double * a);
int main()
{
    int i;
    double ar[LEN];
    double * p;
    p = ar;
    for (i = 0; i < LEN; i++)
        scanf("%lf", &ar[i]);
    paixu(p);
    for (i = 0; i < LEN; i++)
        printf("%lf ", *p++);
    putchar('\n');

    return 0;
}
void paixu(double * a)
{
    int i, u;
    double temp;
    for (i = 0; i < LEN; i++)
        for(u = i+1; u < LEN; u++)
        {
        	if(fabs(a[i]) > fabs(a[u]))
        	{
	        	temp = a[i];
	        	a[i] = a[u];
	        	a[u] = temp;
	        }
        }
}

