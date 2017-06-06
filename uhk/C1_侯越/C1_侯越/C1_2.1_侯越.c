#include<stdio.h>
int main()
{
    int a, b, c, d, e;
    scanf("%d", &a);
    for (c = 1; c <= a; c++)
    {
        for (b = 1; b <= a - c; b++)
        {
            printf(" ");
        }
            if (c == 1 || c == a)
            {
				for (d = 1; d <= (a + (c - 1) * 2 ); d++ )
            	{
                	printf("*");
            	}
          	  	printf("\n");
            }
            else
            { 
                printf("*");
                for (e = 1; e <= (a + (c - 2) * 2); e++)
                printf(" ");
                printf("*\n");
            }
    }
    return 0;
}
