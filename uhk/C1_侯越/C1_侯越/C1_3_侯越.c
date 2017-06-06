#include <stdio.h>
int main()
{
    int a, b, c, S;
    scanf("%d %d %d", &a, &b, &c);
    S = (a * 10 + b) + (a * 10 + c) + (b * 10 + a) + (b * 10 + c) + (c * 10 + a) + (c * 10 + b);
    printf("The sum is %d.\n", S);

    return 0;
}
