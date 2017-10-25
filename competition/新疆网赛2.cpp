#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 1e9+1;
const int maxn = 10000 + 100;
const int maxm = 100000 + 100;
struct Edge
{
    int u;
    int v;
    int w;
};
Edge edge[maxm];
int tot;
void addedge(int u, int v, int w)
{
    edge[tot].u = u;
    edge[tot].v = v;
    edge[tot++].w = w;
}
struct comp
{
    bool operator () (Edge& a, Edge& b)
    {
        return a.w < b.w;
    }
};
int N, M;
bool ar[maxn][2];
int main()
{
    int i, j, k, n, m, a, b, c;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d", &N, &M);
            tot = 0;
            memset(ar, false, sizeof(ar));
            for(i = 1; i <= M; i++)
            {
                scanf("%d %d %d", &a, &b, &c);
                addedge(a, b, c);
            }
            sort(edge, edge + tot, comp());
            for(i = 0; i < tot; i++)
            {
                int u = edge[i].u;
                int v = edge[i].v;
                if()
            }
        }
    }
}