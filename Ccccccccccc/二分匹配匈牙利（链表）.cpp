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
const int maxn = 5010;
const int maxm = 50010;
struct HUNGARY
{
    struct Edge
    {
        int to;
        int next;
    };
    Edge edge[maxm];
    int head[maxn];
    int tol;
    int link[maxn];
    bool visit[maxn];
    int uN;
    void init()
    {
        tol = 0;
        memset(head, -1, sizeof(head));
    }
    void addedge(int u, int v)
    {
        edge[tol].to = v;
        edge[tol].next = head[u];
        head[u] = tol++;
    }
    bool dfs(int u)
    {
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if(!visit[v])
            {
                visit[v] = true;
                if(link[v] == -1 || dfs(link[v]))
                {
                    link[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    int hungary()
    {
        int res = 0;
        memset(link, -1, sizeof(link));
        for(int u = 1; u <= uN; u++)
        {
            memset(visit, false, sizeof(visit));
            if(dfs(u))
                res++;
        }
        return res;
    }
};
HUNGARY hungary;
//初始化 hungary.init()
//要给 uN 赋值才能算
//标号都是从1开始，1~uN
