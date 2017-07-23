#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 210;
const int maxm = 210;
const int INF = 2e10;
struct DINIC
{
    struct Edge
    {
        int to;
        int cap;
        int rev;
    };
    vector<Edge>G[maxm];
    int level[maxn];
    int iter[maxn];
    void clear(int n)
    {
        for(int i = 0; i <= n; i++)
            G[i].clear();
    }
    void addedge(int u, int v, int cap)
    {
        G[u].push_back((Edge){v, cap, G[v].size()});
        G[v].push_back((Edge){u, 0, G[u].size() - 1});
    }
    void bfs(int s)
    {
        int i, j;
        queue<int>q;
        memset(level, -1, sizeof(level));
        level[s] = 0;
        q.push(s);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(i = 0; i < G[u].size(); i++)
            {
                Edge &e = G[u][i];
                if(e.cap > 0 && level[e.to] == -1)
                {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
    }
    int dfs(int st, int end, int flow)
    {
        if(st == end)
            return flow;
        int i, j;
        for(i = iter[st]; i < G[st].size(); i++)
        {
            Edge &e = G[st][i];
            if(e.cap > 0 && level[e.to] == level[st] + 1)
            {
                int d = dfs(e.to, end, min(flow, e.cap));
                if(d > 0)
                {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    iter[st] = i;
                    return d;
                }
            }
        }
        return 0;
    }
    int max_flow(int st, int end)
    {
        int flow = 0;
        while(1)
        {
            memset(iter, 0, sizeof(iter));
            bfs(st);
            if(level[end] == -1)
                return flow;
            int f;
            while((f = dfs(st, end, INF)) > 0)
                flow += f;
        }
    }
};
DINIC dinic;

int main()
{
    int i, j, k, u, a, b, c, n, m;
    while (scanf("%d %d", &m, &n) != EOF)
    {
        dinic.clear(n);
        for (i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            dinic.addedge(a, b, c);
        }
        printf("%d\n", dinic.max_flow(1, n));
    }
    return 0;
}