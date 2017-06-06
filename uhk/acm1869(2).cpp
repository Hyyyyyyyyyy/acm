#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <map>
#include <deque>
using namespace std;
const int MIN = -100000000;
const int MAX = 100000000;
typedef long long ll;
struct node
{
    int to;
    int next;
    int val;
    node() {}
    node(int a, int b, int c) : to(a), next(b), val(c) {}
    bool operator < (const node &p) const
    {
        return val > p.val;
    }
};
node edge[200010];
int head[200010];
int dist[100010];
int cnt, n;
void addedge(int x, int y, int z);
void dijkstra(int s);
int main()
{
    int i, j, u, m, a, b, c, sum, doudou;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        memset(head, -1, sizeof(head));
        cnt = 0;
        for (u = 1; u <= m; u++)
        {
            scanf("%d %d", &a, &b);
            addedge(a, b, 1);
            addedge(b, a, 1);
        }
        doudou = 1;
        for (i = 0; i < n; i++)
        {
            dijkstra(i);
            for (j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                if (dist[j] > 7)
                {    
                    doudou = 0;
                    break;
                }
            }
            if(!doudou)
                break;
        }
        if(doudou)
            printf("Yes\n");
        else
            printf("No\n");
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
void dijkstra(int s)
{
    int i, j, u, t, v;
    node now(s, head[s], 0), after;
    priority_queue<node>q;
    for (i = 0; i < n; i++)
    {
        dist[i] = MAX;
    }
    dist[s] = 0;
    q.push(now);
    while (!q.empty())
    {
        now = q.top();
        q.pop();
        if (dist[now.to] < now.val)
            continue;
        for (i = head[now.to]; i != -1; i = edge[i].next)
        {
            after = edge[i];
            if (dist[after.to] > dist[now.to] + after.val)
            {
                dist[after.to] = dist[now.to] + after.val;
                q.push(after);
            }
        }
    }
}