#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;
const int maxn = 10000 + 10;
int grundy[maxn];
int step[110];
int N;
int getgrundy(int x)
{
    if (grundy[x] != -1)
        return grundy[x];
    int i, j;
    int visit[110];
    memset(visit, 0, sizeof(visit));
    for (i = 1; i <= N; i++)
    {
        if (step[i] <= x)
        {
            visit[getgrundy(x - step[i])] = 1;
        }
        else
            break;
    }
    int res = 0;
    while (visit[res])
        res++;
    grundy[x] = res;
    return res;
}
int main()
{
    int i, j, k, u, n, m, a, b;
    //freopen("OUT.txt", "w", stdout);
    while (scanf("%d", &N) != EOF && N)
    {
        for (i = 1; i <= N; i++)
        {
            scanf("%d", &step[i]);
        }
        sort(step + 1, step + 1 + N);
        memset(grundy, -1, sizeof(grundy));
        scanf("%d", &n);
        for (m = 1; m <= n; m++)
        {
            scanf("%d", &k);
            int res = 0;
            for (u = 1; u <= k; u++)
            {
                scanf("%d", &a);
                res ^= getgrundy(a);
            }
            if (res == 0)
                printf("L");
            else
                printf("W");
        }
        printf("\n");
    }
    return 0;
}