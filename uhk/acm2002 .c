#include <stdio.h>
#include <math.h>
int main()
{
    double r;
    while (scanf("%lf", &r) != EOF)
    {
        printf("%.3lf\n", 4.0/3.0 * 3.1415927 * pow(r, 3.0));
    }
    return 0;
    
}