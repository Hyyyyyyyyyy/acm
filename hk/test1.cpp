#include <stdio.h>
#include <ctype.h>
int main()
{
    char stack[10001];
    int i, j, n, m, top, doudou, doudou2;
    char s[10001];
    while(scanf("%s", s) != EOF)
    {
        top = 0;
        doudou = 1;
        doudou2 = 1;
        stack[0] = '.';
        for(i = 0; s[i] != 0; i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stack[++top] = s[i];
            if(s[i] == ')')
            {
                if(top == 0)
                {
                    doudou2 = 0;
                    break;
                }
                if(stack[top] == '(')
                    top--;
                else
                    doudou = 0;
            }
            if(s[i] == ']')
            {
                if(top == 0)
                {
                    doudou2 = 0;
                    break;
                }
                if(stack[top] == '[')
                    top--;
                else
                    doudou = 0;
            }
            if(s[i] == '}')
            {
                if(top == 0)
                {
                    doudou2 = 0;
                    break;
                }
                if(stack[top] == '{')
                    top--;
                else
                    doudou = 0;
            }
            if(!doudou)
                break;
        }
        if(!doudou)
            printf("error");
        else if(top > 0)
            printf("-1");
        else if(!doudou2)
            printf("1");
        else
            printf("right");
    }
    return 0;
}







#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char s[100001];
    int i, j, k;
    while(scanf("%s", s) != EOF)
    {
        k = strlen(s);
        for(i = 0, j = k-1; i <= j; i++, j--)
        {
            if(s[i] != s[j])
                break;
        }
        if(i > j)
            printf("no");
        else
            printf("yes");
    }
    return 0;
}


#include <stdio.h>
#include <ctype.h>
#include <math.h>
int main()
{
    int i, j, k, n, m;
    int stack[1001];
    int top;
    while(scanf("%d %d", &n, &k) != EOF)
    {
        top = 0;
        while(n / k)
        {
            stack[++top] = n % k;
            n /= k;
        }
        stack[++top] = n;
        for(i = top; i >= 1; i--)
            printf("%d", stack[i]);
    }
    return 0;
}