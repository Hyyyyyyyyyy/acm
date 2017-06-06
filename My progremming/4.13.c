#include<stdio.h>
int main()
{
    int n;

    printf("Please enter three integers :\n");
    scanf("%*d %d %*d", &n);
    printf("The expected integer was %d\n", n);

    return 0;
}
