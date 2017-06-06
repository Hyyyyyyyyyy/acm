#include <stdio.h>
int main()
{
    int r, c, t;

    for (c = 1; c <= 9; c++)
    {
        for (r = 1; r <= c; r++)
        {
            t = c * r;
            printf("%d * %d = %-2d    ", r, c, t);
        }
         printf("\n");
    }
    return 0;
}
