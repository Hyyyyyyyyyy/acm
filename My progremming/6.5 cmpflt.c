#include <stdio.h>
#include<math.h>
int main()
{
    const double ANSWER = 3.1415926;
    double response;

    printf("What is the value of pi?\n");
    scanf("%lf", &response);
    while (fabs(response - ANSWER) > 0.000001)
    {
        printf("PLease try again!\n");
        scanf("%lf", &response);

    }
    printf("Close enough!\n");
}
