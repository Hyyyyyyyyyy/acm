#include <stdio.h>
int main()
{
    int n, ar[20], i, temp;
    printf("Please enter a 'n':\n");
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &ar[i]);
        for (i = 1; i < n; i++)
            if (ar[0] > ar[i])
            {
                temp = ar[i];
                ar[i] = ar[0];
                ar[0] = temp;
            }
        for (i = 0; i < n; i++)
        	printf("%d ", ar[i]);
       	putchar('\n');
        printf("Please enter a 'n' again:\n");
    }
    return 0;
}
