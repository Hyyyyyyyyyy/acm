#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
const int MAXN = 110;
struct node
{
    int to;
    int val;
    int next;
    //bool operator < (const node &p) const
    //{
    //    return val > p.val;
    //}
};
struct point
{
    int to;
    int val;
    bool operator < (const point &p) const
    {
        return val > p.val;
    }
};
node edge[MAXN * 100];
int head[MAXN], visit[MAXN][10010];
bool bfs();
void addedge(int x, int y, int z);
int ar[MAXN][MAXN], va[MAXN];
int cnt, n;
int main()
{
    int i, j, k, u, m, a, b, c;
    while (scanf("%d", &n) != EOF && n != -1)
    {
        memset(ar, 0, sizeof(ar));
        memset(head, -1, sizeof(head));
        cnt = 0;
        for (m = 1; m <= n; m++)
        {
            scanf("%d %d", &a, &b);
            va[m] = a;
            for (i = 1; i <= b; i++)
            {
                scanf("%d", &c);
                ar[m][c] = 1;
            }
        }
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                if (ar[i][j])
                {
                    addedge(i, j, va[j]);
                }
            }
        }
        if (bfs())
            printf("winnable\n");
        else
            printf("hopeless\n");
    }
    return 0;
}
void addedge(int x, int y, int z)
{
    edge[cnt].to = y;
    edge[cnt].val = z;
    edge[cnt].next = head[x];
    head[x] = cnt++;
}
bool bfs()
{
    int i, j, k, u, v, t;
    point now, after;
    priority_queue<point>q;
    memset(visit, 0, sizeof(visit));
    visit[1][100] = 1;
    now.to = 1;
    now.val = 100;
    q.push(now);
    while (!q.empty())
    {
        now = q.top();
        q.pop();
        if (now.to == n && now.val > 0)
            return true;
        for (i = head[now.to]; i != -1; i = edge[i].next)
        {
            after.to = edge[i].to;
            after.val = edge[i].val + now.val;
            if (after.val <= 0)
                continue;
            if (visit[after.to][after.val])
                continue;
            q.push(after);
            visit[after.to][after.val] = 1;
        }
    }
    return false;
}