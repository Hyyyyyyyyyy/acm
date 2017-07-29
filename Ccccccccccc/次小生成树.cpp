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
const int INF = 2147483640;
const int maxn = 205;
struct S_PRIME
{
    int N;
    int cost[maxn][maxn];
    bool visit[maxn];
    int lowc[maxn];
    int pre[maxn];
    int Max[maxn][maxn];
    bool used[maxn][maxn];
    int prime()
    {
        int ans = 0;
        memset(visit, false, sizeof(visit));
        memset(Max, 0, sizeof(Max));
        memset(used, false, sizeof(used));
        visit[1] = true;
        pre[1] = -1;
        for(int i = 2; i <= N; i++)
        {
            lowc[i] = cost[1][i];
            pre[i] = 1;
        }
        lowc[1] = 0;
        for(int i = 2; i <= N; i++)
        {
            int minc = INF;
            int p = -1;
            for(int j = 1; j <= N; j++)
            {
                if(!visit[j] && minc > lowc[j])
                {
                    minc = lowc[j];
                    p = j;
                }
            }
            if(minc == INF)
                return -1;
            ans += minc;
            visit[p] = true;
            used[p][pre[p]] = used[pre[p]][p] = true;
            for(int j = 1; j <= N; j++)
            {
                if(visit[j])
                    Max[j][p] = Max[p][j] = max(Max[j][pre[p]], lowc[p]);
                if(!visit[j] && lowc[j] > cost[p][j])
                {
                    lowc[j] = cost[p][j];
                    pre[j] = p;
                }
            }
        }
        return ans;
    }
};
S_PRIME prime;
//prime.N;
//prime.cost[][]
