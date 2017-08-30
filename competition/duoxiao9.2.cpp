#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
const int INF = 2147483640;
const double eps = 1e-7;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int maxn = 125250 + 100;
ll ar[maxn];
ll stack[maxn];
int main()
{
    int i, j, k, u, n, m, N;
    while(scanf("%d", &N) != EOF)
    {
        for(i = 1; i <= N; i++)
        {
            scanf("%lld", &ar[i]);
        }
        if(N <= 2)
        {
            for(i = 1; i <= N; i++)
            {
                if(i != 1)
                    putchar(' ');
                printf("%lld", stack[i]);
            }
        }
        sort(ar+1, ar+1+N);
        int M = (int)((-1.0 + sqrt(1.0+8.0*N))/2.0);
        ll a, b;
        int top = 0;
        int cur = 2;
        stack[++top] = ar[1];
        stack[++top] = ar[2];
        a = ar[1];
        b = ar[2];
        for(i = 3; i <= N; i++)
        {
            if(a+b == ar[i])
            {
                if(cur < top)
                {
                    a = stack[cur];
                    b = stack[cur+1];
                    cur++;
                }
                else
                {
                    a = stack[cur];
                    b = ar[i+1];
                    stack[++top] = b;
                    cur = top;
                }
                if(top == M)
                    break;
            }
            else
            {
                stack[++top] = ar[i];
                if(top == M)
                    break;
            }
        }
        for(i = 1; i <= top; i++)
        {
            if(i != 1)
                putchar(' ');
            printf("%lld", stack[i]);
        }
        putchar('\n');
    }
    return 0;
}