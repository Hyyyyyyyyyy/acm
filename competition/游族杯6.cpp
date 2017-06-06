#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int stack[100010], top, MAX;
int main()
{
    int i, j, k, u, n, m, a, b, sum;
    while(scanf("%d", &n) != EOF)
    {
        top = 0;
        MAX = 0;
        sum = 0;
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d", &a, &b);
            if(b == 0)
            {
                if(top == 0)
                {
                    sum++;
                    continue;
                }
                for(i = top; i > 0; i--)
                {
                    if(stack[i] < a)
                    {
                        top--;
                    }
                    else if(stack[i] == a)
                        continue;
                    else
                    {
                        break;
                    }
                }
                if(i == 0)
                    sum++;
            }
            else
            {
                stack[++top] = a;
            }
        }
        printf("%d\n", sum+top);
    }
    return 0;
}