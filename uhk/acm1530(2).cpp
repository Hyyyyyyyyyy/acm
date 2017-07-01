#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 60;
int ar[maxn][maxn];
int stack[maxn];
int dp[maxn];
int N, M, RES;
bool check(int a, int b)
{
    int i, j;
    for(i = 1; i <= a; i++)
    {
        if(!ar[stack[i]][b])
            return false;
    }
    return true;
}
void dfs(int top, int now)
{
    int i, j;
    if(top + N-now+1 <= RES)
        return;
    if(top + dp[now] <= RES)
        return;
    for(i = now; i <= N; i++)
    {
        if(check(top, i))
        {
            stack[top+1] = i;
            dfs(top+1, i+1);
        }
    }
    if(RES < top)
        RES = top;
}
int main()
{
    int i, j, k, u, n, m, a, b;
    while(scanf("%d", &N) != EOF && N)
    {
        for(i = 1; i <= N; i++)
        {
            for(j = 1; j <= N; j++)
            {
                scanf("%d", &ar[i][j]);
            }
        }
        memset(dp, 0, sizeof(dp));
        RES = 0;
        dp[N] = 1;
        for(i = N-1; i >= 1; i--)
        {
            stack[1] = i;
            dfs(1, i+1);
            dp[i] = RES;
        }
        printf("%d\n", dp[1]);
    }
    return 0;
}
