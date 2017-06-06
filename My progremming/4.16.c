#include <stdio.h>
#define SQUARES 64
int main() 
{
    const double CROP = 2E16;
    double current, total;
    int count = 1;

    printf("squares         grains         total      ");
    printf("fraction of \n");
    printf("               added         grains      ");
    printf("world total\n");
    total = current = 1.0;
    while (count <= SQUARES )
    {

        printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
        current = 2.0 * current;
        total = total + current;
        count = count + 1;

    }
    printf("That is all.\n");

    return 0;
}

