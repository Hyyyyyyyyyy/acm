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
    int D1;
    int start, end;
    int head[maxn];
    int visit[maxn];
    int dist[maxn];
    
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
    //返回的是最大流，mincost存的是最小费用
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
//别忘了改maxn，maxm
//别忘了给 zkw.start, zkw.end, zkw.N 赋值 和 zkw.init() 初始化
//zkw.N为节点总个数，编号0~N-1
//cost为单位流量，单价为1m/元的路程花费（即为距离）