#include <stdio.h>
#define LEN 5
void huanwei(double * a);
int main()
{
    double * p, ar[LEN];
    int i;

    for(i = 0; i < LEN; i++)
        scanf("%lf", &ar[i]);
    p = ar;
    huanwei(p);
    for (i = 0; i < LEN; i++)
        printf("%lf ", *p++);
    return 0;
}
void huanwei(double * a)
{
    double *max, *min, temp;
    int i;

    max = a;
    min = a;
    for (i = 1; i < LEN; i++)
    {    
        max = (*max > a[i]) ? max:&a[i];
        min = (*min < a[i]) ? min:&a[i];
    }
    temp = *max;
    *max = *min;
    *min = temp;
}
