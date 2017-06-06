#include <stdio.h>
int main()
{
    int zippol[4][2] = { { 2, 4 }, { 6, 8 }, { 1, 3 }, { 5, 7 } };

    printf("zippol = %p,   zippol + 1 = %p\n", zippol, zippol + 1);
    printf("zippol[0] = %p, zippol[0] + 1 = %p\n", zippol[0], zippol[0] + 1);
    printf("*zippol = %p, *zippol + 1 = %p\n", *zippol, *zippol + 1);
    printf("zippol[0][0] = %d\n", zippol[0][0]);
    printf("*zippol[0] = %d\n", *zippol[0]);
    printf("**zippol = %d\n", **zippol);
    printf("zippol[2][1] = %d\n", zippol[2][1]);
    printf("*(*(zippol + 2) + 1) = %d\n", *(*(zippol + 2) +1));

    return 0;
}
