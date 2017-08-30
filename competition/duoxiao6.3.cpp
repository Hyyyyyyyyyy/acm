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
const int maxn = 500 + 10;
int N, K;
int IN[maxn];
vector<int>G[maxn];
int res[maxn];
int dfs(int u)
{
    int i, j;
    for(i = 0; i < G[u].size(); i++)
    {
    	if(G[u][i] == u)
    		continue;
        res[u] += (IN[G[u][i]] == 1 ? 1:0);
    }
}
int main()
{
    int i, j, k, u, n, m;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d", &N, &K);
            for(i = 0; i <= N; i++)
                G[i].clear();
            memset(IN, 0, sizeof(IN));
            memset(res, 0, sizeof(res));
            for(i = 2; i <= N; i++)
            {
                scanf("%d", &u);
                G[i].push_back(u);
                G[u].push_back(i);
                IN[u]++;
                IN[i]++;
            }
            dfs(1);
            int doudou = 0;
            for(i = 1; i <= N; i++)
            {
                if(res[i] >= 1)
                {
                    doudou = 1;
                    break;
                }
            }
            if(doudou)
                printf("Alice\n");
            else
                printf("Bob\n");
        }
    }
    return 0;
}