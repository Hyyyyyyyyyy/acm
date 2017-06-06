#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
struct node
{
    int x;
    int y;
    int sta;
    int turn;
};
struct node now, after;
int dir[4][2] = { 0, 1, 0, -1, -1, 0, 1, 0 };
int visit[105][105];
char ar[105][105];
int n, m, x1, y1, x2, y2, k;
queue<node>q;
void bfs();
int main()
{
    int i, j, u, a, b;
    struct node temp;
    while (scanf("%d", &a) != EOF)
    {
        for (b = 1; b <= a; b++)
        {
            scanf("%d %d", &n, &m);
            for (i = 1; i <= n; i++)
            {
                scanf("%s", ar[i] + 1);
            }
            scanf("%d %d %d %d %d", &k, &y1, &x1, &y2, &x2);
            if (ar[x2][y2] == '*' || ar[x1][y1] == '*' || k < 0)
            {
                printf("no\n");
                continue;
            }
            while (!q.empty())
                q.pop();
            for (i = 0; i <= n; i++)
            {
                for (j = 0; j <= m; j++)
                {
                    visit[i][j] = 10000000;
                }
            }
            for (i = 0; i < 4; i++)
            {
                temp.x = x1;
                temp.y = y1;
                temp.sta = i;
                temp.turn = 0;
                q.push(temp);
            }
            bfs();
            if (visit[x2][y2] >= 0 && visit[x2][y2] <= k)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
void bfs()
{
    int i, j, u;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        for (i = 0; i < 4; i++)
        {
            after.x = now.x + dir[i][0];
            after.y = now.y + dir[i][1];
            if (now.sta != i)
            {
                after.sta = i;
                after.turn = now.turn + 1;
            }
            else
            {
                after.sta = i;
                after.turn = now.turn;
            }
            if (after.turn > k || (after.turn == k && after.x != x2 && after.y != y2))
                continue;
            if (after.x < 1 || after.y < 1 || after.x > n || after.y > m || ar[after.x][after.y] == '*')
                continue;
            if (ar[after.x][after.y] == '.' && visit[after.x][after.y] >= after.turn)
            {
                q.push(after);
                visit[after.x][after.y] = after.turn;
            }
        }
    }
    return;
}