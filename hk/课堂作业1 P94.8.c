#include <stdio.h>
int main()
{
    int P = 1;
    int n, m, s;
    printf("Please enter an n to limit the number of ingeter:\n");
    scanf("%d", &n);
    for (m = 1; m <= n; m++)
    {
    	printf("Please keep enter number.\n");
        scanf("%d", &s);
        if (s % 2 == 0)
        	P = P * s;
    }
    printf("The finall P is %d.\n", P);
    return 0;
}
