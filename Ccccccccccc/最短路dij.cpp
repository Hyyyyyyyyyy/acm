#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-7;
const int INF = 1000000000;
const int maxn = 205;
struct DIJ
{
    int g[maxn][maxn];
    int dist[maxn];
    int start;
    int N;
    bool visit[maxn];
    int pre[maxn];
    void dijkstra()
    {
        for(int i = 0; i <= N; i++)
        {
            dist[i] = INF;
            visit[i] = false;
            pre[i] = -1;
        }
        dist[start] = 0;
        for(int i = 1; i <= N; i++)
        {
            int k = -1;
            int Min = INF;
            for(int j = 1; j <= N; j++)
            {
                if(!visit[j] && dist[j] < Min)
                {
                    Min = dist[j];
                    k = j;
                }
            }
            if(k == -1)
                break;
            visit[k] = true;
            for(int j = 1; j <= N; j++)
            {
                if(!visit[j] && dist[j] > dist[k] + g[k][j])
                {
                    dist[j] = dist[k] + g[k][j];
                    pre[j] = k;
                }
            }
        } 
    }
};
DIJ dij;
//先给g[][], start, N 赋值
