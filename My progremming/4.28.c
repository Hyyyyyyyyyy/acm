#include <stdio.h>
#define SIZE 10
#define PAR 72
int main()
{
    int index, score[SIZE];
    int sum = 0;
    float average;

    printf("Enter %d golf score:\n", SIZE);
    for (index = 0; index < SIZE; index++)
        scanf("%d", &score[index]);
    printf("The scores read in are as follows:\n");
    for (index = 0; index < SIZE; index++)
        scanf("%5d", score[index]);
    printf("\n");
    for (index = 0; index < SIZE; index++)
        sum += score[index];
    average = (float) sum / SIZE;
    printf("Sum of scores = %d, average = %.2f\n", sum, average);
    printf("That is a handicap of %.1f.\n", average - PAR);

    return 0;
}
