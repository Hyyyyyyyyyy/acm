#include <stdio.h>
#include <stdbool.h>
int main()
{
    unsigned long num;
    unsigned long div;
    bool isprime;

    printf("please enter an integer for analysis; ");
    while (scanf("%lu", &num) == 1)
    {
        for (div = 2, isprime = true; (div * div) <= num; div++)
        {
            if (num % div == 0)
            {
                if ((div *div) != num)
                printf("%lu is divisible by %lu and %lu.\n", num, div, num / div);
                else
                    printf("%lu is divisible by %lu.\n", num, div);
                isprime = false;
            }
        }
        if (isprime)
            printf("%lu is prime.\n", num);
        printf("Please enter another integer for analysis; ");
    }
    printf("Bye .\n");

    return 0;
}

