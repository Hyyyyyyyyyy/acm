#include <stdio.h>
#define LEN 5
int main()
{
    double ar[LEN], * p, * q, temp;
    int i, u;

    for (i = 0; i < LEN; i++)
        scanf("%lf", &ar[i]);
    
    for (i = 0; i < LEN; i++)
    {
        p = &ar[i];
        for (u = i+1; u < LEN; u++)
        {
            q = &ar[u];
            if(*p > *q)
            {
                temp = *p;
                *p = *q;
                *q = temp;
            }
        }
    }
    p = ar;
    for (i = 0; i < LEN; i++)
        printf("%lf ", *p++);
    putchar('\n');
    return 0;
}
