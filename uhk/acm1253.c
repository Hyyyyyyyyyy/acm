#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
struct node
{
    int x;
    int y;
    int z;
    int time;
};
struct node now, after;
int a, b, c, t;
int dir[6][3] = { { 0, 0, 1 },{ 0, 0, -1 },{ 0, -1, 0 },{ 0, 1, 0 },{ 1, 0, 0 },{ -1, 0, 0 } };
int visit[55][55][55], ar[55][55][55];
void bfs();
int main()
{
    int i, j, k, u, n, m;
    while (scanf("%d", &n) != EOF)
    {
        for (m = 0; m < n; m++)
        {
            scanf("%d %d %d %d", &a, &b, &c, &t);
            for (u = 1; u <= a; u++)
            {
                for (i = 1; i <= b; i++)
                {
                    for (j = 1; j <= c; j++)
                    {
                        scanf("%d", &ar[u][i][j]);
                        visit[u][i][j] = 10000000;
                    }
                }
            }
            bfs();
            if (visit[a][b][c] != 10000000 && visit[a][b][c] <= t)
                printf("%d\n", visit[a][b][c]);
            else
                printf("-1\n");
        }
    }
    return 0;
}
void bfs()
{
    int i, j, k, u;
    queue<node>q;
    now.x = 1;
    now.y = 1;
    now.z = 1;
    now.time = 0;
    q.push(now);
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        for (i = 0; i < 6; i++)
        {
            after.x = now.x + dir[i][0];
            after.y = now.y + dir[i][1];
            after.z = now.z + dir[i][2];
            after.time = now.time + 1;
            if (after.x < 1 || after.y < 1 || after.z < 1 || after.x > b || after.y > c || after.z > a)
                continue;
            if (ar[after.z][after.x][after.y] == 1)
                continue;
            if (after.time > t || (after.time == t && (after.x != b || after.y != c || after.z != a)))
                continue;
            if (ar[after.z][after.x][after.y] == 0 && after.time < visit[after.z][after.x][after.y])
            {
                q.push(after);
                visit[after.z][after.x][after.y] = after.time;
            }
        }
    }
    return;
}