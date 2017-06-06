#include <stdio.h>
#include <math.h>
int main()
{
    int n, i;
    double s;
    n = 1;
    i = 1;
    s = 0.0;

    printf("Please wait for a moment patiently, it will finish soon!\n");
    while (n > 1.0e-15)
    {
        s = s + 1.0 / n * i;
        i = i * (-1);
        n = n + 2;
        printf(" %.9lf\n", s * 4);
    }
    printf("¦Ð = %.9lf\n", s * 4);

    return 0;
}

