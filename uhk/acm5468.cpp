#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 2147483640;
const int maxn = 100000;
bool check[maxn + 10];
int prime[maxn + 10];
int mu[maxn + 10];
vector<int> factors[maxn + 10];
vector<int> G[maxn + 10];
void Moblus()
{
    memset(check, false, sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for(int i = 2; i <= maxn; i++)
    {
        if(!check[i])
        {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot; j++)
        {
            if(i * prime[j] > maxn)
                break;
            check[i * prime[j]] = true;
            if(i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    for(int i = 2; i <= maxn; i++)
        if(mu[i])
        {
            for(int j = i; j <= maxn; j += i)
            {
                factors[j].push_back(i);
            }
        }
}
//???? < tot
int val[maxn+10];
int cnt[maxn], sz[maxn], ans[maxn];
void dfs(int u, int fa)
{
    sz[u] = 1;
    vector<int>pre;
    for(int i = 0; i < factors[val[u]].size(); i++)
    {
        int d = factors[val[u]][i];
        pre.push_back(cnt[d]);
        cnt[d]++;
    }
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(v == fa)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    ans[u] = sz[u];
    for(int i = 0; i < factors[val[u]].size(); i++)
    {
        int d = factors[val[u]][i];
        int c = cnt[d] - pre[i];
        if(c)
            ans[u] += mu[d] * c;
    }
}
int main()
{
    int i, j, k, u, n, m, cas = 1, a, b;
    Moblus();
    while(scanf("%d", &n) != EOF)
    {
        for(i = 0; i <= n; i++)
            G[i].clear();
        for(m = 1; m <= n-1; m++)
        {
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &val[i]);
        }
        memset(cnt, 0, sizeof(cnt));
        dfs(1, 0);
        printf("Case #%d:", cas++);
        for(i = 1; i <= n; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }   
    return 0;
}