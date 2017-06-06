#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, k, u, n, m;
    while(scanf("%d", &n) != EOF)
    {
        n += 1;
        if(n % 8 == 3 || n % 8 == 7)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}