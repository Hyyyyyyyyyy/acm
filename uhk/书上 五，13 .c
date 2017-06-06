#include <stdio.h>
#include <math.h>
long double cal(long double e);
long double jc(int a);
int main()
{
    int n;
    double E, sum = 0;

    printf("Please enter a accuracy:\n");
    scanf("%d", &n);
    for (E = 1.0e-1; E >= pow(10, -n); E = E / 10.0)
    {
        sum = cal(E);
        printf("Sum = %.15lf.\n", sum);
    }

    return 0;
}

long double cal(long double e)
{
    int i;
    long double S = 0.0;
    for(i = 1; jc(i) > e; i++)
		S = S + jc(i);
    
    return S;
}

long double jc(int a)
{
	long double T = 1;
	if (a == 1)
	return 1;
	else
	{
		T = jc(a - 1) * (1.0 / a);
		return T;
	}
}
