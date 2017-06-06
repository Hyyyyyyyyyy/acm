#include <stdio.h>
int main()
{
    int i;
    float max = 0, min = 100, ar[10], sum = 0;

    for (i = 0; i < 10; i++)
    {
    	scanf("%f", &ar[i]);
       	max = (ar[i] > max) ? ar[i]:max;
        min = (ar[i] < min) ? ar[i]:min;
        sum += ar[i];
    }
    printf("The average is %.2f.\n", (sum - max - min) / 8.0);
    return 0;
}
