#include <cstdio>
#include <queue>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 210;
const int maxm = 100010;
const int INF = 0x3f3f3f3f;
struct ZKW
{
    int start, end;
    int N;
    int mincost;
    int maxflow;
    int tol;
    int head[maxn];
    int cap[maxm], cost[maxm], to[maxm], next[maxm];        //单位流量，单价为1m/元的路程花费（即距离）
    int dist[maxn];
    int visit[maxn];
    void init()
    {
        memset(head, -1, sizeof(head));
        tol = 0;
        mincost = maxflow = 0;
    }
    void addedge(int u, int v, int capp, int costt)
    {
        to[tol] = v;
        cap[tol] = capp; 
        cost[tol] = costt;
        next[tol] = head[u];
        head[u] = tol++;
        to[tol] = u;
        cap[tol] = 0;
        cost[tol] = -costt;
        next[tol] = head[v];
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
            for(int p = head[u]; p != -1; p = next[p])
            {
                int &v = to[p];
                if(cap[p] && dist[v] > d + cost[p])
                {
                    dist[v] = d + cost[p];
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
        for(int p = head[u]; p != -1; p = next[p])
        {
            int &v = to[p];
            if(cap[p] && !visit[v] && dist[u] == dist[v] + cost[p])
            {
                int tmp = add_flow(v, min(now, cap[p]));
                cap[p] -= tmp;
                cap[p ^ 1] += tmp;
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
                for(int p = head[u]; p != -1; p = next[p])
                {
                    int &v = to[p];
                    if(cap[p] && !visit[v]) 
                        d = min(d, dist[v] + cost[p] - dist[u]);
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