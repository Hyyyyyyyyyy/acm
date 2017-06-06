#include <stdio.h>
int main()
{
    int n, ar[100], temp, i, *min, doudou;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        for (i = 0; i < n; i++)
            scanf("%d", &ar[i]);
        min = &ar[n-1];
        for (i = (n - 1); i >= 0; i--)
            min = (*min < ar[i]) ? min:&ar[i];
        temp = ar[0];
        ar[0] = *min;
        *min = temp;
        doudou = 0;
        for (i = 0; i < n; i++)
        {
        	if (doudou == 1)
        		putchar(' ');
        	printf("%d", ar[i]);
			doudou = 1;	
        }
        putchar('\n');
    }
    return 0;
}
