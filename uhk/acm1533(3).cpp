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
    struct Edge
    {
        int to;
        int next;
        int cap;        //该边的最大流量
        int flow;       //该边的流量
        int cost;       //单位流量，单价为1m/元的路程花费（即距离）
    };
    Edge edge[maxm];
    int tol;
    int N;               //节点总个数，节点编号0~N-1
    int maxflow;
    int mincost;
    int start, end;
    int head[maxn];
    bool visit[maxn];
    int dist[maxn];
    void init()
    {
        memset(head, -1, sizeof(head));
        tol = 0;
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
    void SPFA()
    {
        for(int i = 0; i <= N; ++i) 
            dist[i] = INF;
        priority_queue<pair<int, int> > Q;
        dist[start] = 0;
        Q.push(make_pair(0, start));
        while(!Q.empty())
        {
            int u = Q.top().second;
            int d = -Q.top().first;
            Q.pop();
            if(dist[u] != d) 
                continue;
            for(int p = head[u]; p != -1; p = edge[p].next)
            {
                int &v = edge[p].to;
                if(edge[p].cap && dist[v] > d + edge[p].cost)
                {
                    dist[v] = d + edge[p].cost;
                    Q.push(make_pair(-dist[v], v));
                }
            }
        }
        for(int i = 0; i <= N; ++i) 
            dist[i] = dist[end] - dist[i];
    }

    int add_flow(int u, int flow)
    {
        if(u == end)
        {
            maxflow += flow;
            mincost += dist[start] * flow;
            return flow;
        }
        visit[u] = true;
        int now = flow;
        for(int p = head[u]; p != -1; p = edge[p].next)
        {
            int &v = edge[p].to;
            if(edge[p].cap && !visit[v] && dist[u] == dist[v] + edge[p].cost)
            {
                int tmp = add_flow(v, min(now, edge[p].cap));
                edge[p].cap -= tmp;
                edge[p ^ 1].cap += tmp;
                now -= tmp;
                if(!now) 
                    break;
            }
        }
        return flow - now;
    }

    bool modify_label()
    {
        int d = INF;
        for(int u = 0; u <= N; ++u) 
            if(visit[u])
                for(int p = head[u]; p != -1; p = edge[p].next)
                {
                    int &v = edge[p].to;
                    if(edge[p].cap && !visit[v]) 
                        d = min(d, dist[v] + edge[p].cost - dist[u]);
                }
        if(d == INF) 
            return false;
        for(int i = 0; i <= N; ++i) 
            if(visit[i]) 
                dist[i] += d;
        return true;
    }

    int minCostMaxFlow()
    {
        mincost = maxflow = 0;
        SPFA();
        while(true)
        {
            while(true)
            {
                for(int i = 0; i <= N; ++i) 
                    visit[i] = 0;
                if(!add_flow(start, INF))
                    break;
            }
            if(!modify_label()) 
                break;
        }
        return mincost;
    }
};
ZKW zkw;
//别忘了改maxn，maxm
//别忘了给 zkw.start, zkw.end, zkw.N 赋值 和 zkw.init() 初始化
//zkw.N为节点总个数，编号0~N-1
//cost为单位流量，单价为1m/元的路程花费（即为距离）
//minCostMaxFlow()返回的是最小费用，maxflow是最大流

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
        printf("%d\n", zkw.minCostMaxFlow());
    }
    return 0;
}