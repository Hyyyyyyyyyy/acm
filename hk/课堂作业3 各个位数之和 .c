#include <stdio.h>
int main()
{
    int n, m, a, b, s;
    s = 0;

    printf("Please enter an n, then output sum of all the digit:\n");
    scanf("%d", &n);
    while(n > 0)
    {
    	a = n % 10;
    	s = s + a;
    	n = (n - a) / 10;
    }
    
    printf("The sum is %d", s);

    return 0;
}
