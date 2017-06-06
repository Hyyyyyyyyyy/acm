#include <stdio.h>
#include <math.h>
int F(double a, double b);
int main()
{
    double x1 = 0.0, x2 = 5.0, S;
    while (fabs(x1 - x2) > 1.0e-6)
    {
        S = F(x1, x2);
        if (F((x1 + x2) / 2.0, x1) == 1)
        	x2 = (x1 + x2) / 2.0;
         else
         	x1 = (x1 + x2) / 2.0;
        if (S != 0 && S != 1)
        {
			printf("The root of equation is %.6lf.\n", S);
        	break;
        }
    }
    printf("The root of equation is %.6lf.\n", (x1 + x2) / 2.0);

    return 0;
}

int F(double a, double b)
{
    _Bool doudou;
    double x, y1, y2;

    x = a;
    y1 = x * x + x * sin(x) - 5;
    x = b;
    y2 = x * x + x * sin(x) - 5;
    if (y1 * y2 == 0)
        return (y1 == 0) ? a:b;
    else if (y1 * y2 < 0)
    {   
        doudou = 1;
        return doudou;
    }
    else
    {
        doudou = 0;
        return doudou;
    }
}
