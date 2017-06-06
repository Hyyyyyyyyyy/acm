#include <stdio.h>
int main()
{
    int i , j, k, u, n, m, count, L;
    char ar[1100];
    while(gets(ar) != EOF && ar[0] != '#')
    {
        count = 0;
        L = strlen(ar);
        for(i = 0; i < L-1; i++)
            if(ar[i] == '1')
                count++;
        if(count % 2 == 0 && ar[L-1] == 'f')
        {
            ar[L-1] = '0';
            puts(ar);
        }
        else if(count % 2 == 0 && ar[L-1] == 'u')
        {
            ar[L-1] = '1';
            puts(ar);
        }
        else if(count % 2 != 0 && ar[L-1] = 'f')
        {
            ar[L-1] = '1';
            puts(ar);
        }
        else
        {
            ar[L-1] = '0';
            puts(ar);
        }
    }
    return 0;
}