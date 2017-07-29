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
struct PRIME
{
    int N;
    int cost[maxn][maxn];
    int lowc[maxn];
    bool visit[maxn];
    int prime()
    {
        int ans = 0;
        memset(visit, false, sizeof(visit));
        visit[1] = true;
        for(int i = 2; i <= N; i++)
            lowc[i] = cost[1][i];
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
            for(int j = 1; j <= N; j++)
            {
                if(!visit[j] && lowc[j] > cost[p][j])
                    lowc[j] = cost[p][j];
            }
        }
        return ans;
    }
};
PRIME prime;
//prime.N
//1~N;
//prime.cost[][]
