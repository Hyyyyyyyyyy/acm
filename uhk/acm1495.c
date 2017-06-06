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
    int count;
};
struct node now, after;
int s, m, n;
int dir[6][3];
int visit[102][102][102];
void bfs();
int main()
{
    int i, j, k, u, temp;
    while (scanf("%d %d %d", &s, &n, &m) != EOF && (s || n || m))
    {
        if (s % 2 == 1)
        {
            printf("NO\n");
            continue;
        }
        if (n < m)
        {
            temp = n;
            n = m;
            m = temp;
        }
        bfs();
        if (visit[s / 2][s / 2][0] != 10000000)
            printf("%d\n", visit[s / 2][s / 2][0]);
        else
            printf("NO\n");
    }
    return 0;
}
void bfs()
{
    int i, j, k, u;
    queue<node>q;

    for (i = 0; i <= s; i++)
    {
        for (j = 0; j <= n; j++)
        {
            for (k = 0; k <= m; k++)
            {
                visit[i][j][k] = 10000000;
            }
        }
    }
    now.x = s;
    now.y = 0;
    now.z = 0;
    now.count = 0;
    q.push(now);
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        for (i = 1; i <= 6; i++)
        {
            if (i == 1 && now.x)
            {
                if (now.x + now.y >= n)
                {
                    after.x = now.x - n + now.y;
                    after.y = n;
                    after.z = now.z;
                    after.count = now.count + 1;
                }
                else
                {
                    after.x = 0;
                    after.y = now.y + now.x;
                    after.z = now.z;
                    after.count = now.count + 1;
                }
                if (after.x < 0 || after.y < 0 || after.z < 0 || after.x > s || after.y > n || after.z > m)
                    continue;
                if (after.count < visit[after.x][after.y][after.z])
                {
                    q.push(after);
                    visit[after.x][after.y][after.z] = after.count;
                }
            }
            if (i == 2 && now.x)
            {
                if (now.x + now.z >= m)
                {
                    after.x = now.x - m + now.z;
                    after.y = now.y;
                    after.z = m;
                    after.count = now.count + 1;
                }
                else
                {
                    after.x = 0;
                    after.y = now.y;
                    after.z = now.z + now.x;
                    after.count = now.count + 1;
                }
                if (after.x < 0 || after.y < 0 || after.z < 0 || after.x > s || after.y > n || after.z > m)
                    continue;
                if (after.count < visit[after.x][after.y][after.z])
                {
                    q.push(after);
                    visit[after.x][after.y][after.z] = after.count;
                }
            }
            if (i == 3 && now.y)
            {
                if (now.y + now.x >= s)
                {
                    after.x = s;
                    after.y = now.y - s + now.x;
                    after.z = now.z;
                    after.count = now.count + 1;
                }
                else
                {
                    after.x = now.x + now.y;
                    after.y = 0;
                    after.z = now.z;
                    after.count = now.count + 1;
                }
                if (after.x < 0 || after.y < 0 || after.z < 0 || after.x > s || after.y > n || after.z > m)
                    continue;
                if (after.count < visit[after.x][after.y][after.z])
                {
                    q.push(after);
                    visit[after.x][after.y][after.z] = after.count;
                }
            }
            if (i == 4 && now.y)
            {
                if (now.y + now.z >= m)
                {
                    after.x = now.x;
                    after.y = now.y - m + now.z;
                    after.z = m;
                    after.count = now.count + 1;
                }
                else
                {
                    after.x = now.x;
                    after.y = 0;
                    after.z = now.y + now.z;
                    after.count = now.count + 1;
                }
                if (after.x < 0 || after.y < 0 || after.z < 0 || after.x > s || after.y > n || after.z > m)
                    continue;
                if (after.count < visit[after.x][after.y][after.z])
                {
                    q.push(after);
                    visit[after.x][after.y][after.z] = after.count;
                }
            }
            if (i == 5 && now.z)
            {
                if (now.z + now.x >= s)
                {
                    after.x = s;
                    after.y = now.y;
                    after.z = now.z - s + now.x;
                    after.count = now.count + 1;
                }
                else
                {
                    after.x = now.x + now.z;
                    after.y = now.y;
                    after.z = 0;
                    after.count = now.count + 1;
                }
                if (after.x < 0 || after.y < 0 || after.z < 0 || after.x > s || after.y > n || after.z > m)
                    continue;
                if (after.count < visit[after.x][after.y][after.z])
                {
                    q.push(after);
                    visit[after.x][after.y][after.z] = after.count;
                }
            }
            if (i == 6 && now.z)
            {
                if (now.z + now.y >= n)
                {
                    after.x = now.x;
                    after.y = n;
                    after.z = now.z - n + now.y;
                    after.count = now.count + 1;
                }
                else
                {
                    after.x = now.x;
                    after.y = now.y + now.z;
                    after.z = 0;
                    after.count = now.count + 1;
                }
                if (after.x < 0 || after.y < 0 || after.z < 0 || after.x > s || after.y > n || after.z > m)
                    continue;
                if (after.count < visit[after.x][after.y][after.z])
                {
                    q.push(after);
                    visit[after.x][after.y][after.z] = after.count;
                }
            }
        }
    }
    return;
}
