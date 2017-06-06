#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAX = 11;
ll dp[11][11];
int ar[11];
int Count;
ll dfs(int pos, int pre, int limit, int first);
ll solve(ll n);
int main()
{
    int i, j, u, max, a, b;
    ll n, m, k, res;
    memset(dp, -1, sizeof(dp));
    while (scanf("%d", &a) != EOF)
    {
        for (b = 1; b <= a; b++)
        {
            scanf("%lld %lld", &n, &m);
            //printf("%lld %lld\n", solve(m), solve(n - 1));
            printf("%lld\n", solve(m) - solve(n - 1));
        }
    }
    return 0;
}
ll solve(ll n)
{
    int i, j;
    Count = 0;
    while (n)
    {
        ar[++Count] = n % 10;
        n /= 10;
    }
    return dfs(Count, 0, 1, 1);
}
ll dfs(int pos, int pre, int limit, int first)
{
    int i, j, k, max;
    ll res = 0;
    if (pos == 0)
        return 1;
    if (!limit && dp[pos][pre] != -1)
        return dp[pos][pre];
    max = limit ? ar[pos] : 9;
    for (i = 0; i <= max; i++)
    {
        if(first)
            res += dfs(pos - 1, i, limit && i == ar[pos], first && i== 0);
        else if(i == 0)
            continue;
        else if(i > pre || pre % i)
            continue;
        else
            res += dfs(pos - 1, i, limit && i == ar[pos], first && i== 0);
    }
    if (!limit)
        dp[pos][pre] = res;
    return res;
}