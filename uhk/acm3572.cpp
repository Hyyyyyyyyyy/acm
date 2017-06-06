#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;
int ar[600][600];
int Max;
int dinic();
int dfs(int st, int ed, int fl);
int bfs(int st, int ed);
int dep[600];
const int main()
{
    int i, j, k, u, n, m, a, b, c, p, q, r;
    while(scanf("%d", &n) != EOF)
    {
        for(m  = 1; m <= n; m++)
        {
            memset(ar, 0, sizeof(ar));
            Max = 0;
            for(i = 0; i <= 500; i++)
            {
                ar[0][i] = b;
            }
            scanf("%d %d", &a, &b);
            for(i = 1; i <= a; i++)
            {
                scanf("%d %d %d", &r, &p, &q);
                Max = (Max < q) ? q:Max;
                for(j = p; j <= q; j++)
                {
                    for(k = j+1; k <= q; k++)
                    {
                        ar[j][k] += 1;
                    }
                }
            }
            for(i = 0; i <= 500; i++)
            {
                ar[i][Max+1] = b;
            }
            printf("%d\n", dinic());
        }
    }
    return 0;
}
int dinic()
{
    int i, j, res = 0, temp;
    while(bfs(0, Max+1))
    {
        while(1)
        {
            temp = dfs(0, Max+1, Max);
            if(temp == 0)
                break;
            res += temp;
        }
    }
    return res;
}
int dfs(int st, int ed, int fl)
{
    int i, j, k, temp, flow;
    if(st == ed)
        return fl;
    for(i = 0; i <= Max+1; i++)
    {
        if(ar[st][i] && dep[i] == -1)
        {
            flow = (fl < ar[st][i]) ? fl:ar[st][i];
            if(temp = dfs(i, ed, flow))
            {
                ar[st][i] -= temp;
                ar[i][st] += temp;
                return temp;
            }
        }
    }
    return 0;
}
int bfs(int st, int ed)
{
    int i, j, k, u, t;
    queue<int>q;
    memset(dep, -1, sizeof(dep));
    dep[st] = 0;
    q.push(st);
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        for(i = 1; i <= Max+1; i++)
        {
            if(dep[i] == -1 && ar[t][i])
            {
                dep[i] = dep[t] + 1;
                q.push(i);
            }
        }
    }
    if(dep[ed] == -1)
        return 0;
    return 1;
}