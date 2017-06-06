#include <cstdio>
#include <cstring>
#include <deque>
#include <vector>
#include <algorithm>
#define MAX 100000000
using namespace std;

struct node
{
    int now;
    int val;
    int next;
};
struct node ar[20010];
int head[10010], dist[10010], num[10010], n, m;
bool visit[10010];
void P_SPFA();

int main()
{
    int i, j, k, u, a, b, c, count;
    while (scanf("%d %d", &n, &m) != EOF && (n || m))
    {
        count = 0;
        memset(head, -1, sizeof(head));
        memset(visit, false, sizeof(visit));
        memset(num, 0, sizeof(num));
        for (u = 1; u <= m; u++)
        {
            scanf("%d %d %d", &a, &b, &c);
            ar[count].now = b;
            ar[count].val = c;
            ar[count].next = head[a];
            head[a] = count;
            count++;
            ar[count].now = a;
            ar[count].val = c;
            ar[count].next = head[b];
            head[b] = count;
            count++;
        }
        P_SPFA();
        printf("%d\n", dist[n]);
    }
    return 0;
}
void P_SPFA()
{
    int i, j, k, u, temp, after;
    deque<int>q;
    for (i = 0; i <= n; i++)
        dist[i] = MAX;
    dist[1] = 0;
    temp = 1;
    q.push_back(temp);
    while (!q.empty())
    {
        temp = q.front();
        q.pop_front();
        visit[temp] = false;
        for (i = head[temp]; i != -1; i = ar[i].next)
        {
            after = ar[i].now;
            if (dist[after] > dist[temp] + ar[i].val)
            {
                dist[after] = dist[temp] + ar[i].val;
                if (!visit[after])
                {
                    visit[after] = true;
                    num[after]++;
                    if (num[after] >= n)
                        return;
                    if (!q.empty() && dist[after] < dist[q.front()])
                        q.push_front(after);
                    else
                        q.push_back(after);
                }
            }
        }
    }
}