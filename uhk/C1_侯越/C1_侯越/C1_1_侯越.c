#include<stdio.h>
int main(void)
{
    float Pi = 3.14;
    float r, h, S, V;

    printf("Please enter r :");
    scanf("%f",&r);
    printf("Please enter h :");
    scanf("%f",&h);

    S = 2 * Pi * r * r + 2 * Pi * r * h;
    V = Pi * r * r * h;
    printf("The circular cylinder's superficial area is %.2f and volume is %.2f\n",S, V);

    return 0;

}
