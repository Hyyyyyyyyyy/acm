#include <stdio.h>
int F(int n);
int main()
{
    int a, judge;
    
    printf("Please enter numbers, we will find out ");
    printf("whether it is a wanshu (any alpha to quit):\n");
    while (scanf("%d", &a) == 1)
	{
		if (a > 0)
		{
		    judge = F(a);
		    if (judge == 1)
		        printf("Yes! It is wanshu.\n");
		    else
		        printf("No! It is not wanshu.\n");
		}
		else
			printf("It is not positive integer.\n");
    }
    return 0;
}

int F(int n)
{
    int sum = 0, i;

    for (i = 1; i < n; i++)
        sum = (n % i == 0) ? (sum + i):sum;
    if (sum == n)
        return 1;
    else
        return 0;
}
