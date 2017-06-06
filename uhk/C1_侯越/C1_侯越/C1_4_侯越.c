#include <stdio.h>
int main()
{
    int n;
    int a = 0;
    printf("Please enter a number which is < 1000 :\n");
    scanf("%d", &n);
    while (n != 1)
    {
        if (n % 2 == 0)
        n = n / 2;
        else
        n = (3 * n + 1) / 2;
        a = a + 1;
    }
    printf("The times that n becomes 1 is %d.", a);
}
