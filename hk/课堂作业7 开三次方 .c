#include<stdio.h>
#include<math.h>
int main()
{
    double x0, x1, a;

	printf("Please enter a dear number£¬then we will give you its cubic root:\n");
    scanf("%lf", &a);
    x0 = a;
    x1 = (2.0 / 3 * x0 + a / (3.0 * x0 * x0));
 
    while (x1 * x1 * x1 - a > 1.0e-10)
    {
        x0 = x1;
        x1 = (2.0 / 3 * x0 + a / (3.0 * x0 * x0));
    }
    printf("x ^ 1/3 = %.10lf\n", x1);
    printf("x ^ 1/3 = %.10lf", pow(a,(1.0/3)));

    return 0;
}
