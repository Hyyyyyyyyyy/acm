#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
    int x;
    int y;
    int time;
};
node now, after;
int dir[4][2] = { -1, 0, 0, -1, 1, 0, 0, 1 };
int visit[10][10];
char ar[10][10];
int beginx, beginy, N, M, T, endx, endy;
bool dfs(int b, int e, int t);
int main()
{
    int i, j, k, u, n, m;
    while (scanf("%d %d %d", &N, &M, &T) != EOF && (N || M || T))
    {
        for (i = 1; i <= N; i++)
        {
            scanf("%s", ar[i] + 1);
            for (j = 1; j <= M; j++)
            {
                if (ar[i][j] == 'S')
                {
                    beginx = i;
                    beginy = j;
                }
                if (ar[i][j] == 'D')
                {
                    endx = i;
                    endy = j;
                }
            }
        }
        memset(visit, 0, sizeof(visit));
        if (dfs(beginx, beginy, 0))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
bool dfs(int b, int e, int t)
{
    int i, j, u, v, temp;
    if (ar[b][e] == 'D' && t == T)
        return true;
    visit[b][e] = 1;
    for (i = 0; i < 4; i++)
    {
        after.x = b + dir[i][0];
        after.y = e + dir[i][1];
        after.time = t + 1;
        if (after.x < 1 || after.x > N || after.y < 1 || after.y > M || visit[after.x][after.y] || ar[after.x][after.y] == 'X')
            continue;
        if ((after.time == T && ar[after.x][after.y] != 'D') || (after.time != T && ar[after.x][after.y] == 'D'))
            continue;
        temp = (T - after.time) - abs(after.x - endx) - abs(after.y - endy);
        if (temp % 2 != 0 || temp < 0)
            continue;
        if (dfs(after.x, after.y, after.time))
            return true;
    }
    visit[b][e] = 0;
    return false;
}