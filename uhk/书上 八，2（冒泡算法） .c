#include <stdio.h>
#include <math.h>
void sort(double * ar, int a);
int main()
{
    int i;
    double sa[10];
    for (i = 0; i < 10; i++)
        scanf("%lf", &sa[i]);
    sort(sa, 10);
    for (i = 0; i < 10; i++)
        printf("%.2lf  ", sa[i]);
    
    return 0;
}

void sort(double * ar, int a)
{
    int n, i;
	double N = 0; 
    for (n = 0; n < a; n++)
    {
        for (i = (a - 1); i > n; i--)
        {
        	if (fabs(ar[i]) < fabs(ar[i-1]))
            {
                N = ar[i-1];
                ar[i-1] = ar[i];
                ar[i]= N;
            }
        }
    }
    return;
}
