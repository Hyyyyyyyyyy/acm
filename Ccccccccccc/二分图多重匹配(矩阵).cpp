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
const int maxn = 510;       //左边点数
const int maxm = 1010;      //右边点数
struct Max_HUNGARY
{
    int uN, vN;
    int g[maxn][maxm];
    int link[maxm][maxn];       //link[i][0]是右边点i已连接的左边点个数
    bool visit[maxm];
    int num[maxm];
    void init()
    {
        memset(g, 0, sizeof(g));
    }
    bool dfs(int u)
    {
        for(int v = 1; v <= vN; v++)
        {
            if(g[u][v] && !visit[v])
            {
                visit[v] = true;
                if(link[v][0] < num[v])
                {
                    link[v][++link[v][0]] = u;
                    return true;
                }
                for(int i = 1; i <= link[v][0]; i++)
                {
                    if(dfs(link[v][i]))
                    {
                        link[v][i] = u;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    int Max_hungary()
    {
        int res = 0;
        for(int i = 1; i <= vN; i++)
            link[i][0] = 0;
        for(int u = 1; u <= uN; u++)
        {
            memset(visit, false, sizeof(visit));
            if(dfs(u))
                res++;
        }
        return res;
    }
};
Max_HUNGARY hungary;
//初始化hungary.init()
//要先给uN，vN赋值才能算
