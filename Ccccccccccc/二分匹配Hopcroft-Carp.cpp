#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int INF = 2147483640;
typedef long long ll;
const int maxn1 = 3000;
const int maxn2 = 3000;
struct HC
{
    vector<int>G[maxn1];
    int uN;
    int Mx[maxn1], My[maxn2];
    int dx[maxn1], dy[maxn2];
    int dist;
    bool visit[maxn2];
    void init()
    {
        for(int i = 0; i <= uN; i++)
            G[i].clear();
    }
    void addedge(int u, int v)
    {
        G[u].push_back(v);
    }
    bool SearchP()
    {
        queue<int>Q;
        dist = INF;
        memset(dx, -1, sizeof(dx));
        memset(dy, -1, sizeof(dy));
        for(int i = 1; i <= uN; i++)
        {
            if(Mx[i] == -1)
            {
                Q.push(i);
                dx[i] = 0;
            }
        }
        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            if(dx[u] > dist)
                break;
            int sz = G[u].size();
            for(int i = 0; i < sz; i++)
            {
                int v = G[u][i];
                if(dy[v] == -1)
                {
                    dy[v] = dx[u] + 1;
                    if(My[v] == -1)
                        dist = dy[v];
                    else
                    {
                        dx[My[v]] = dy[v] + 1;
                        Q.push(My[v]);
                    }
                }
            }
        }
        return dist != INF;
    }
    bool dfs(int u)
    {
        int sz = G[u].size();
        for(int i = 0; i < sz; i++)
        {
            int v = G[u][i];
            if(!visit[v] && dy[v] == dx[u] + 1)
            {
                visit[v] = true;
                if(My[v] != -1 && dy[v] == dist)
                    continue;
                if(My[v] == -1 || dfs(My[v]))
                {
                    My[v] = u;
                    Mx[u] = v;
                    return true;
                }
            }
        }
        return false;
    }
    int MaxMatch()
    {
        int res = 0;
        memset(Mx, -1, sizeof(Mx));
        memset(My, -1, sizeof(My));
        while(SearchP())
        {
            memset(visit, false, sizeof(visit));
            for(int i = 1; i <= uN; i++)
            {
                if(Mx[i] == -1 && dfs(i))
                    res++;
            }
        }
        return res;
    }
};
HC hop;
//要先给uN赋值
//初始化hop.init()