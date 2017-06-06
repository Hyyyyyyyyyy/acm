#include <stdio.h>
void value(int * ar, int n, int x);
int main()
{
    int n, x, i;
    scanf("%d %d", &n, &x);

    int sa[n];
    value(sa, n, x);
    for (i = 0; i < n; i++)
        printf("%d  ", sa[i]);

        return 0;
}

void value(int * ar, int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {    
        *ar = x;
        ar++;
    }
    return;
}
