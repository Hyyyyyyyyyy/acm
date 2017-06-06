#include <stdio.h>
int main()
{
    int s, d;
    s = d = 1;

    while (d < 10)
    {
        s = (s + 1) * 2;
        d = d + 1;
    }

    printf("The number of all the peaches is %d.\n", s);
    return 0;
}
