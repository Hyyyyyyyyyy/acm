#include <stdio.h>
#include <ctype.h>
int main()
{
    char ar[2000];
    int i, j, k, n, m, count;
    while(scanf("%s", ar) != EOF)
    {
        count = 0;
        for(i = 0; ar[i] != '\0'; i++)
        {
            if(isupper(ar[i]))
            {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}