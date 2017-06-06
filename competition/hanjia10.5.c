#include <stdio.h>
#include <stdlb.h>
#include <string.h>
int main()
{
    char ar[51], s[51], a[51], b[51];
    int i, j, k, u, n, m, L, max, count, doudou;
    while(scanf("%s", s) != EOF)
    {
        L = strlen(s);
        count = 0;
        scanf("%d", &n);
        if(strstr(s, "*") == NULL)
        {
            for(m = 1; m <= n; m++)
            {
                scanf("%s", ar);
                if(strcmp(ar, s) == 0)
                    count++;
            }
            printf("%d\n", count);
        }
        else
        {
            for(m = 1; m <= n; m++)
            {
                scanf("%s", ar);
                for(i = 0; ar[i] != '\0'; i++)
                {
                    if(ar[i] != s[i] && (s[i] == '*' || s[i] == '?'))
                    {
                        if(s[i] == '?')
                            continue;
                        else if(s[i] == '*')
                        {
                            doudou = 1;
                        }
                    }
                }
            }
            
        }
    }
}