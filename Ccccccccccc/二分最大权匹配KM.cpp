#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 2147483640;
const int maxn1 = 310;
const int maxn2 = 310;
struct KM
{
    int nx, ny;     //两边的点数
    int g[maxn1][maxn2];        //二分图关系
    int link[maxn2];
    int lx[maxn1], ly[maxn2];       //对另一边点的最大要求值
    int visitx[maxn1], visity[maxn2];       //在一次增广中是否被增广到
    int slack[maxn2];
    void init()
    {
        memset(g, 0, sizeof(g));
    }
    bool dfs(int x)
    {
        visitx[x] = true;
        for(int y = 1; y <= ny; y++)
        {
            if(visity[y])
                continue;
            int tmp = lx[x] + ly[y] - g[x][y];
            if(tmp == 0)
            {
                visity[y] = true;
                if(link[y] == -1 || dfs(link[y]))
                {
                    link[y] = x;
                    return true;
                }
            }
            else if(slack[y] > tmp)
            {
                slack[y] = tmp;
            }
        }
        return false;
    }
    int km()
    {
        memset(link, -1, sizeof(link));
        memset(ly, 0, sizeof(ly));
        for(int i = 1; i <= nx; i++)
        {
            lx[i] = -INF;
            for(int j = 1; j <= ny; j++)
            {
                if(g[i][j] > lx[i])
                {
                    lx[i] = g[i][j];
                }
            }
        }
        for(int x = 1; x <= nx; x++)
        {
            for(int i = 1; i <= ny; i++)
                slack[i] = INF;
            while(true)
            {
                memset(visitx, false, sizeof(visitx));
                memset(visity, false, sizeof(visity));
                if(dfs(x))
                    break;
                int d = INF;
                for(int i = 1; i <= ny; i++)
                {
                    if(!visity[i] && d > slack[i])
                    {
                        d = slack[i];
                    }
                }
                for(int i = 1; i <= nx; i++)
                {
                    if(visitx[i])
                        lx[i] -= d;
                }
                for(int i = 1; i <= ny; i++)
                {
                    if(visity[i])
                        ly[i] += d;
                    else
                        slack[i] -= d;
                }
            }
        }
        int res = 0;
        for(int i = 1; i <= ny; i++)
        {
            if(link[i] != -1)
                res += g[link[i]][i];
        }
        return res;
    }
};
KM km;
//要先给nx，ny赋值才能算
//如果g图不是每个点都有权值，先全部赋值为0
//如果算最小权值，把权值都取负数，结果再取负数
