#include <stdio.h>
int main()
{
    int t, n, i;

    printf("Please enter your grade:\n");
    while (scanf("%d", &t) == 1)
    {
        if (t < 0 || t > 100)
        printf("Are you kidding?\n");
        else
        {
            n = t / 10;
            switch (n)
            {
                case 10:
                case 9:
                    putchar('A');
                    break;
                case 8:
                    putchar('B');
                    break;
                case 7:
                    putchar('C');
                    break;
                case 6:
                    putchar('D');
                    break;
                default:
                    putchar('E');
            }
        }
    }
    return 0;
}
