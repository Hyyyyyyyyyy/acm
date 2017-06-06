#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
const int MAX = 100000000;
using namespace std;
struct node
{
    int x;
    int y;
    int z;
    int step;
    friend bool operator < (node a, node b)
    {
        return a.step > b.step;
    }
};
struct node now, after;
int visit[2][20][20], a, b, t, x1, y1, x2, y2, z1, z2;
int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1};
char ar[2][20][20];
void bfs();
int main()
{
    int i, j, k, n, m, u;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d %d", &a, &b, &t);
            for(u = 0; u < 2; u++)
            {
                for(i = 1; i <= a; i++)
                {
                    scanf("%s", ar[u][i]+1);

                    for(j = 1; j <= b; j++)
                    {
                        if(ar[u][i][j] == 'S')
                        {
                            x1 = i;
                            y1 = j;
                            z1 = u;
                        }
                        if(ar[u][i][j] == 'P')
                        {
                            x2 = i;
                            y2 = j;
                            z2 = u;
                        }
                    }

                }
            }
            bfs();
            if(ar[now.z][now.x][now.y] == 'P' && now.step <= t)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
void bfs()
{
    int u, i, j, k, temp;
    priority_queue<node>q;
    for(u = 0; u < 2; u++)
    {
        for(i = 0; i <= a; i++)
        {
            for(j = 0; j <= b; j++)
            {
                visit[u][i][j] = MAX;
            }
        }
    }
    now.x = x1;
    now.y = y1;
    now.z = z1;
    now.step = 0;
    visit[z1][x1][y1] = 0;
    q.push(now);
    while(!q.empty())
    {
        now = q.top();
        q.pop();
        if(ar[now.z][now.x][now.y] == 'P' && now.step <= t)
            return;
        for(i = 0; i < 4; i++)
        {
            after.x = now.x + dir[i][0];
            after.y = now.y + dir[i][1];
            after.z = now.z;
            after.step = now.step + 1;
            if(after.x < 1 || after.x > a || after.y < 1 || after.y > b || ar[after.z][after.x][after.y] == '*' || after.step > t)
                continue;

            if(ar[after.z][after.x][after.y] == '#')
            {
                temp = (after.z == 0) ? 1:0;
                if(ar[temp][after.x][after.y] == '#' || ar[temp][after.x][after.y] == '*')
                    continue;
                
                if(visit[temp][after.x][after.y] > after.step && visit[after.z][after.x][after.y] > after.step)
                {
                	visit[after.z][after.x][after.y] = after.step;
                    after.z = temp;
                    q.push(after);
                    visit[temp][after.x][after.y] = after.step;
                }
                continue;
            }
            if((ar[after.z][after.x][after.y] == '.' || ar[after.z][after.x][after.y] == 'P') && visit[after.z][after.x][after.y] > after.step)
            {
                q.push(after);
                visit[after.z][after.x][after.y] = after.step;
            }
        }
    }
    now.step = MAX;
}
