
#include <cstdio>
#include <queue>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define mul(a) (a)*(a)
using namespace std;
const int Maxn = 210;
const int Maxm = 100010;
const int inf = 0x3f3f3f3f;
struct ZKW_flow
{
    int st, ed, ecnt, n;
    int head[Maxn];
    int cap[Maxm], cost[Maxm], to[Maxm], next[Maxm];
    void init()
    {
        memset(head, -1, sizeof(head));
        ecnt = 2;
    }
    void AddEdge(int u, int v, int cc, int ww)
    {
        cap[ecnt] = cc; cost[ecnt] = ww; to[ecnt] = v;
        next[ecnt] = head[u]; head[u] = ecnt++;
        cap[ecnt] = 0; cost[ecnt] = -ww; to[ecnt] = u;
        next[ecnt] = head[v]; head[v] = ecnt++;
    }
    int dis[Maxn];
    void SPFA()
    {
        for(int i = 0; i <= n; ++i) dis[i] = inf;
        priority_queue<pair<int, int> > Q;
        dis[st] = 0;
        Q.push(make_pair(0, st));
        while(!Q.empty()){
            int u = Q.top().second, d = -Q.top().first;
            Q.pop();
            if(dis[u] != d) continue;
            for(int p = head[u]; p!=-1; p = next[p]){
                int &v = to[p];
                if(cap[p] && dis[v] > d + cost[p]){
                    dis[v] = d + cost[p];
                    Q.push(make_pair(-dis[v], v));
                }
            }
        }
        for(int i = 0; i <= n; ++i) dis[i] = dis[ed] - dis[i];
    }
    int minCost, maxFlow;
    bool use[Maxn];
    int add_flow(int u, int flow)
    {
        if(u == ed)
        {
            maxFlow += flow;
            minCost += dis[st] * flow;
            return flow;
        }
        use[u] = true;
        int now = flow;
        for(int p = head[u]; p!=-1; p = next[p])
        {
            int &v = to[p];
            if(cap[p] && !use[v] && dis[u] == dis[v] + cost[p])
            {
                int tmp = add_flow(v, min(now, cap[p]));
                cap[p] -= tmp;
                cap[p^1] += tmp;
                now -= tmp;
                if(!now) break;
            }
        }
        return flow - now;
    }

    bool modify_label()
    {
        int d = inf;
        for(int u = 0; u <= n; ++u) if(use[u])
            for(int p = head[u]; p!=-1; p = next[p])
            {
                int &v = to[p];
                if(cap[p] && !use[v]) d = min(d, dis[v] + cost[p] - dis[u]);
            }
        if(d == inf) return false;
        for(int i = 0; i <= n; ++i) if(use[i]) dis[i] += d;
        return true;
    }

    int ZKW(int ss, int tt, int nn)
    {
        st = ss, ed = tt, n = nn;
        minCost = maxFlow = 0;
        SPFA();
        while(true)
        {
            while(true)
            {
                for(int i = 0; i <= n; ++i) use[i] = 0;
                if(!add_flow(st, inf)) break;
            }
            if(!modify_label()) break;
        }
        return minCost;
    }
} G;
struct Point
{
    int x , y , z;
    int w;
}P[Maxn];
int dis(Point A , Point B)
{
    return (int) sqrt(1.0 * mul(A.x - B.x) + 1.0 * mul(A.y - B.y) + 1.0 * mul(A.z - B.z));
}
int main()
{
    int N;
    while(scanf("%d",&N)!=EOF && N)
    {
        G.init();
        int sum = 0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d%d%d",&P[i].x , &P[i].y , &P[i].z , &P[i].w);
            sum += P[i].w;
        }
        int s = 0 , t = 2 * N + 1;
        for(int i=1;i<=N;i++)
        {
            G.AddEdge(s , i ,  P[i].w , 0);
            G.AddEdge(N + i , t , P[i].w , 0);
            for(int j=i+1;j<=N;j++)
            {
                int  d = dis(P[i] , P[j]);
                G.AddEdge(i , N + j , inf , d);
                G.AddEdge(j , N + i , inf , d);
            }
        }
        int ans = G.ZKW(s , t , t + 1);
        if(G.maxFlow != sum) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}

