#include<stdio.h>
#define BOOK "War and Peace"
int main()
{
    float cost = 12.99;
    float percent = 80.0;

    printf("This copy of \"%s\" sells for $%5.2f.\n"
"That is %.0f%% of list.\n", BOOK, cost, percent);

    return 0;
}
