#include <stdio.h>
#include <math.h>
int main()
{
    double x1, x2, y1, y2;
    while (scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) != EOF)
    {
        printf("%.2lf\n", pow(pow(x1-x2, 2.0)+pow(y1-y2, 2.0), 1.0/2.0));
        
    }
    return 0;
}
