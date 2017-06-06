#include <stdio.h>
int main()
{
    int i;
    double T, m, n;
    i = 1;
    n = 1.0;
    m = 2.0;
    T = 2.0;

    printf("Please wait for a moment patiently, it will finish soon!\n");
    while ((1.0 / m) > 1.0e-10)
    {
        if (i % 2 != 0)
            n = n + 2.0;
        else
            m = m + 2.0;
        T = T * (m / n);
        printf("%.15lf\n", T * 2.0);
        i++;
    }
    printf("¦Ð = %.15lf\n", T * 2.0);

    return 0;
}

