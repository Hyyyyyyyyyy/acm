#include <stdio.h>
int main()
{
    int i, n;
    double s;
    s = 1;
    n = 1;
    i = 1;

    while (i < 40)
    {
        i++;
        n = (-1) * n;
        s = s + 1.0 / i * n;
    }
    printf("s = %.10f\n", s);

    return 0;
}
