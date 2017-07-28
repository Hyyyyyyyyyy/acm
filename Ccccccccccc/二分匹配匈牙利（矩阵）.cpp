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
const int maxn = 510;
struct HUNGARY
{
    int uN;
    int vN;
    int g[maxn][maxn];      //邻接矩阵
    int link[maxn];
    bool visit[maxn];
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
//初始化hungary.init()
//要给 uN和vN 赋值才能算，uN表示左点，vN表示右点
//标号都是从1开始，1~uN， 1~vN
