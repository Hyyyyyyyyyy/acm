#include <stdio.h>
int main()
{
    int n, m, i, u;
    char ar[1005];
    while (scanf("%d", %n) != EOF)
    {
        for(i = 0;;i++)
        {
            scanf("%c", &ar[i]);
            if (ar[i] == '\n')
                break;
        }
        for (u = 0; u < i; u++)
        {
            if(isalpha(ar[u]))
                ar[u] = toupper(ar[u]);
            if(isdigit(ar[u]))
                ar[u] = ar[u] + 1;
        }
        for (u = 0; u < i; u++)
            printf("%c", ar[u]);
    }
    return 0;
}
