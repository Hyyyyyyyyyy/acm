#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cctype>
using namespace std;
const int MAXN = 2e5 + 10;
typedef long long ll;
ll color[MAXN], sz[MAXN], sum[MAXN], vis[MAXN];
vector <int> tree[MAXN];
ll ans;

ll dfs(int u, int pa) 
{
    sz[u] = 1;
    ll allson = 0;
    int cnt = tree[u].size();
    for (int i = 0; i < cnt; i++) 
    {
        int v = tree[u][i];
        if (v == pa) continue;
        ll last = sum[color[u]];            
        sz[u] += dfs(v, u);
        ll add = sum[color[u]] - last;
        ans += (sz[v] - add) * (sz[v] - add - 1) / 2;    
        allson += sz[v] - add;        
    }
    sum[color[u]] += allson + 1;        
    return sz[u];
}

int main() 
{
    int n, cas = 0;
    while (scanf("%d", &n) !=EOF) 
    {
        memset(vis, 0, sizeof(vis));
        memset(sum, 0, sizeof(sum));
        int cnt = 0;
        for (int i = 1; i <= n; i++)
         {
            scanf("%I64d", &color[i]);
            if (!vis[color[i]]) 
                ++cnt;
            vis[color[i]] = 1;
            tree[i].clear();
        }
        for (int i = 1; i < n; i++) 
        {
            int u, v;
            scanf("%d%d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        printf("Case #%d: ", ++cas);
        if (cnt == 1) 
        {     
            printf("%I64d\n", (ll)n * (n - 1ll) / 2ll);
            continue;
        }
        ans = 0;
        dfs(1, -1);
        for (int i = 1; i <= n; i++) 
        {  
            if (!vis[i]) continue;
            ans += (n - sum[i]) * (n - sum[i] - 1ll) / 2ll;
        }
        printf("%I64d\n", (ll)n * (n - 1ll) / 2ll * cnt - ans);
    }
    return 0;
}