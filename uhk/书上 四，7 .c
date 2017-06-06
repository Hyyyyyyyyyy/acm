#include <stdio.h>
int main()
{
    int year, month, day;
    int m, d, sum1 = 0, sum2 = 0;

    printf("Please enter the year:\n");
    scanf("%d", &year);
    printf("Please enter the month:\n");
    scanf("%d", &month);
    printf("Please enter the day:\n");
    scanf("%d", &day);
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        int MONTH1[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        for (m = 0; m < (month - 1); m++)       		
            sum1 += MONTH1[m]; 
        sum1 += day;
        printf("The day is %d\n", sum1);
    }
    else
    {
        int MONTH2[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
         for (m = 0; m < (month - 1); m++)
            sum2 += MONTH2[m];
        sum2 += day;
        printf("The day is %d\n", sum2);
    }
    return 0;
}
