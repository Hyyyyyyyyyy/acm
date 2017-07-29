#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <deque>
using namespace std;
typedef long long ll;
const double eps = 1e-7;
const int INF = 1000000000;
const int maxn = 205;
const int maxm = 1000;
struct P_SPFA
{
    struct Edge
    {
        int to;
        int val;
        int next;
    };
    Edge edge[maxm];
    int tol;
    int N;
    int start;
    int head[maxn];
    int dist[maxn];
    int in[maxn];
    int visit[maxn];
    void init()
    {
        memset(head, -1, sizeof(head));
        tol = 0;
    }
    void addedge(int u, int v, int w)
    {
        edge[tol].to = v;
        edge[tol].val = w;
        edge[tol].next = head[u];
        head[u] = tol++;
    }
    bool P_spfa()
    {
        int i, j, k;
        deque<int>Q;
        for(i = 0; i <= N; i++)
        {
            visit[i] = false;
            in[i] = 0;
            dist[i] = INF;
        }
        visit[start] = true;
        dist[start] = 0;
        Q.push_back(start);
        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop_front();
            visit[u] = false;
            for(i = head[u]; i != -1; i = edge[i].next)
            {
                int v = edge[i].to;
                int w = edge[i].val;
                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    if(!visit[v])
                    {
                        visit[v] = true;
                        if(++in[v] > N)
                            return false;
                        if(!Q.empty() && dist[v] < dist[Q.front()])
                            Q.push_front(v);
                        else
                            Q.push_back(v);
                    }
                }
            }
        }
    }
};
P_SPFA spfa;
//spfa.start, spfa.N, spfa.init()
