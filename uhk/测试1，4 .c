#include <stdio.h>
int main()
{
    int height, weight, standrad;
    scanf("%d %d", &height, &weight);
    standrad = height - 110;
    if (weight >= (standrad + 5))
        printf("fat\n");
    if (weight <= (standrad - 5))
        printf("thin\n");
    if (weight >= (standrad - 5) && weight <= (standrad + 5))
        printf("good\n");

    return 0;
}
