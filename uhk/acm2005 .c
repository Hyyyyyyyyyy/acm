#include <stdio.h>
void F(int Y, int M, int D);
int main()
{
    int a, b, c;
    while (scanf("%d/%d/%d", &a, &b, &c) != EOF)
    {
        F(a,b,c);
    }
    return 0;
}

void F(int Y, int M, int D)
{
	int m, d, sum1 = 0, sum2 = 0;
	if ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0))
    {
        int MONTH1[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        for (m = 0; m < (M - 1); m++)       		
            sum1 += MONTH1[m]; 
        sum1 += D;
        printf("%d\n", sum1);
    }
    else
    {
        int MONTH2[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
         for (m = 0; m < (M - 1); m++)
            sum2 += MONTH2[m];
        sum2 += D;
        printf("%d\n", sum2);
    }
    return;
}