#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
#define retrun return
const ll inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const ll maxn = 10000 + 100;
const ll maxm = 1000000 + 100;
struct Node
{
    ll id;
    ll sum;
    char s[3];
};
Node node[maxn];
ll N, M;
vector<int> G[maxn];
ll dp[maxn][2];
bool dfs(ll u, ll fa)
{
    ll i, j, k;
    ll res0 = 1;
    for (i = 0; i < G[u].size(); i++)
    {
        ll v = G[u][i];
        if (v == fa)
            continue;
        if (!dfs(v, u))
        {
            return false;
        }
        res0 += dp[v][0];
    }
    dp[u][0] = max(res0, dp[u][0]);
    if (dp[u][0] > dp[u][1])
        return false;
    return true;
}
int main()
{
    ll i, j, k, a, b;
    while (scanf("%lld", &N) != EOF)
    {
        for (i = 1; i <= N; i++)
        {
            G[i].clear();
            dp[i][0] = 1;
            dp[i][1] = 1e9;
        }
        for (i = 2; i <= N; i++)
        {
            scanf("%lld", &a);
            G[a].push_back(i);
        }
        scanf("%lld", &M);
        for (i = 1; i <= M; i++)
        {
            scanf("%lld %s %lld", &node[i].id, node[i].s, &node[i].sum);
            if (node[i].s[0] == '=')
            {
                dp[node[i].id][0] = dp[node[i].id][1] = node[i].sum;
            }
            else if (node[i].s[0] == '<')
            {
                dp[node[i].id][1] = min(dp[node[i].id][1], node[i].sum-1);
            }
            else
            {
                dp[node[i].id][0] = max(dp[node[i].id][0], node[i].sum+1);
            }
        }
        if (dfs(1, 0))
            printf("True\n");
        else
            printf("Lie\n");
    }
    return 0;
}