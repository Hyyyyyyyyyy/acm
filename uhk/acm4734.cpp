#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;
typedef long long ll;
ll dp[11][5000];
int ar[11];
ll Pow[13];
ll RES;
ll dfs(int pos, int limit, int sta);
int main()
{
    int i, j, u, a, b, cas, count;
    ll n, m, k;
    Pow[1] = 1;
    for (i = 2; i < 13; i++)
    {
        Pow[i] = Pow[i - 1] * 2;
    }
    memset(dp, -1, sizeof(dp));
    while (scanf("%d", &a) != EOF)
    {
        cas = 1;
        for (b = 1; b <= a; b++)
        {
            scanf("%lld %lld", &n, &m);
            RES = 0;
            i = 1;
            while (n)
            {
                RES += (n % 10) * Pow[i++];
                n /= 10;
            }
            count = 0;
            while (m)
            {
                ar[++count] = m % 10;
                m /= 10;
            }
            printf("Case #%d: %lld\n", cas++, dfs(count, 1, RES));
        }
    }
    return 0;
}
ll dfs(int pos, int limit, int sta)
{
    int i, j, k, max;
    ll res = 0;
    if (pos == 0)
        return sta >= 0;
    if (sta < 0)
        return 0;
    if (!limit && dp[pos][sta] != -1)
        return dp[pos][sta];
    max = limit ? ar[pos] : 9;
    for (i = 0; i <= max; i++)
    {
        res += dfs(pos - 1, limit && i == ar[pos], sta - i * Pow[pos]);
    }
    if (!limit)
        dp[pos][sta] = res;
    return res;
}