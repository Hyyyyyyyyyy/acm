#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <queue>  
#include <cmath>  
#include <algorithm>  
#include <deque>  
using namespace std;
typedef long long ll;
const int INF = 2147483640;
const int maxn = 10000;
const int maxm = 200000;
struct ZKW
{
    int mincost, D1;
    int start, end;
    struct Edge
    {
        int to;
        int next;
        int cap;
        int cost;
        int flow;
    };
    Edge edge[maxm];
    int tol;
    int N;
    int head[maxn];
    int visit[maxn];
    int dist[maxn];
    int maxflow;

    void init()
    {
        memset(head, -1, sizeof head);
        tol = 0;
        mincost = D1 = 0;
    }
    void addedge(int u, int v, int cap, int cost)
    {
        edge[tol].to = v;
        edge[tol].cap = cap;
        edge[tol].cost = cost;
        edge[tol].flow = 0;
        edge[tol].next = head[u];
        head[u] = tol++;
        edge[tol].to = u;
        edge[tol].cap = 0;
        edge[tol].cost = -cost;
        edge[tol].flow = 0;
        edge[tol].next = head[v];
        head[v] = tol++;
    }
    int aug(int u, int f)
    {
        if (u == end)
        {
            mincost += D1 * f;
            maxflow += f;
            return f;
        }
        visit[u] = 1;
        int tmp = f;
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (edge[i].cap > edge[i].flow && edge[i].cost == 0 && !visit[v])
            {
                int d = aug(v, tmp < edge[i].cap - edge[i].flow ? tmp : edge[i].cap - edge[i].flow);
                edge[i].flow += d;
                edge[i ^ 1].flow -= d;
                tmp -= d;
                if (!tmp) return f;
            }
        }
        return f - tmp;
    }
    bool modLabel()
    {
        for (int i = 0; i <= N; i++)
            dist[i] = INF;
        dist[end] = 0;
        deque<int> q;
        q.push_back(end);
        while (!q.empty())
        {
            int dt;
            int u = q.front();
            q.pop_front();
            for (int i = head[u]; i != -1; i = edge[i].next)
            {
                int v = edge[i].to;
                if (edge[i ^ 1].cap > edge[i ^ 1].flow && (dt = dist[u] - edge[i].cost) < dist[v])
                {
                    dist[v] = dt;
                    int tmp = INF;
                    if (q.size() > 0)
                        tmp = dist[q.front()];
                    if (dt <= tmp)
                        q.push_front(v);
                    else
                        q.push_back(v);
                }
            }
        }
        for (int i = 0; i <= end; ++i)
        {
            for (int j = head[i]; j != -1; j = edge[j].next)
            {
                int v = edge[j].to;
                edge[j].cost += dist[v] - dist[i];
            }
        }
        D1 += dist[start];
        return dist[start] < INF;
    }
    int minCostMaxFlow()
    {
        maxflow = 0;
        while (modLabel())
        {
            do
                memset(visit, 0, sizeof(visit));
            while (aug(start, INF));
        }
        return maxflow;
    }
};
ZKW zkw;

struct Node
{
    int x;
    int y;
};
Node np[110], nh[110];
char s[200];
int N, M;
int main()
{
    int i, j, k, u, n, m, a, b, c;
    while (scanf("%d %d", &N, &M) != EOF && N + M)
    {
        zkw.init();
        int cntp = 0;
        int cnth = 0;
        for (i = 0; i < N; i++)
        {
            scanf("%s", s);
            for (j = 0; j < M; j++)
            {
                if (s[j] == 'H')
                {
                    nh[++cnth].x = i;
                    nh[cnth].y = j;
                }
                if (s[j] == 'm')
                {
                    np[++cntp].x = i;
                    np[cntp].y = j;
                }
            }
        }
        zkw.start = 0;
        zkw.end = cntp + cnth + 1;
        zkw.N = cntp + cnth + 2;
        for (i = 1; i <= cntp; i++)
        {
            for (j = 1; j <= cnth; j++)
            {
                int t = abs(np[i].x - nh[j].x) + abs(np[i].y - nh[j].y);
                zkw.addedge(i, cntp + j, 1, t);
            }
        }
        for (i = 1; i <= cntp; i++)
        {
            zkw.addedge(0, i, 1, 0);
        }
        for (i = 1; i <= cnth; i++)
        {
            zkw.addedge(cntp + i, zkw.end, 1, 0);
        }
        int res = 0;
        zkw.minCostMaxFlow();
        printf("%d\n", zkw.mincost);
    }
    return 0;
}