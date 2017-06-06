#include <stdio.h>
int main()
{
    int row, n, i;

    for (row = 7; row >= 1; row--)
    {
        if (row % 2 == 0)
            printf("\n");
        else
        {
            for (n = 1; n <= (row - 1); n++)
                printf(" ");
            for (i = 1; i <= (8 - row); i++)
                printf("* ");
        }
    }
    printf("\n");
    for (row = 5; row >= 1; row--)
    {
        if (row % 2 == 0)
            printf("\n");
        else
        {
            for (n = 1; n <= (7 - row); n++)
                printf(" ");
            for (i = 1; i <= row; i++)
                printf("* ");
        }
    }
    return 0;
}
