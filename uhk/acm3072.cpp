#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
typedef long long ll;
int dfn[50010], low[50010];
int Stack[50010], Instack[50010];
int head[50010], belong[50010], hd[50010];
int visit[100010];
int cost[100010];
struct node
{
    int from;
    int to;
    int val;
    int next;
};
struct node edge[100010], e[100010];
int Sccc, top, tot, Index, cnt;
void addedge(int x, int y, int z);
void solve(int n, int m);
void Tarjan(int f);
bool comp(int a, int b)
{
    return a > b;
}
int main()
{
    int i, j, k, n, m, a, b, c;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        top = Index = Sccc = cnt = tot = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(Instack, 0, sizeof(Instack));
        memset(head, -1, sizeof(head));
        memset(hd, -1, sizeof(hd));
        memset(belong, -1, sizeof(belong));
        memset(cost, 0, sizeof(cost));
        for (i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            addedge(a, b, c);
        }
        solve(n, m);
    }
    return 0;
}
void addedge(int x, int y, int z)
{
    edge[cnt].from = x;
    edge[cnt].to = y;
    edge[cnt].val = z;
    edge[cnt].next = head[x];
    head[x] = cnt++;
}
void Tarjan(int f)
{
    int i, j, t;
    Stack[top++] = f;
    Instack[f] = 1;
    low[f] = dfn[f] = ++Index;
    for (i = head[f]; i != -1; i = edge[i].next)
    {
        t = edge[i].to;
        if (!dfn[t])
        {
            Tarjan(t);
            if (low[t] < low[f])
                low[f] = low[t];
        }
        else if (Instack[t] && low[f] > dfn[t])
            low[f] = dfn[t];
    }
    if (low[f] == dfn[f])
    {
        Sccc++;
        do
        {
            t = Stack[--top];
            Instack[t] = 0;
            belong[t] = Sccc;
        } while (t != f);
    }
}
void solve(int n, int m)
{
    int i, j, k, t;
    ll sum = 0;
    for (i = 0; i < n; i++)
    {
        if (!dfn[i])
            Tarjan(i);
    }
    for (i = 0; i < n; i++)
        cost[i] = MAX;
    for (i = 0; i < n; i++)
    {
        for (j = head[i]; j != -1; j = edge[j].next)
        {
            if (belong[i] != belong[edge[j].to])
            {
                cost[belong[edge[j].to]] = (cost[belong[edge[j].to]] > edge[j].val) ? edge[j].val : cost[belong[edge[j].to]];
            }
        }
    }
    sort(cost, cost + n, comp);
    for (i = 0; i < n; i++)
        if (cost[i] != MAX)
            sum += cost[i];
    printf("%lld\n", sum);
}