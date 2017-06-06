#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int Stack[5010], Instack[5010];
int dfn[5010], low[5010];
int head[5010], hd[5010];
int belong[5010], num[5010], res[5010], visit[5010], in[5010];
int Index, top, cnt, Sccc, tot;
int ans;
struct node
{
    int from;
    int next;
    int to;
};
node edge[60010], e[60010];
void add(int x, int y);
void ad(int x, int y);
void Tarjan(int f);
int dfs(int n);
void solve(int n, int m, int cas);
int main()
{
    int i, j, k, n, m, a, b, c, p, q, N, M;
    while (scanf("%d", &n) != EOF)
    {
        for (m = 1; m <= n; m++)
        {
            top = Index = cnt = Sccc = ans = tot = 0;
            memset(dfn, 0, sizeof(dfn));
            memset(Instack, 0, sizeof(Instack));
            memset(head, -1, sizeof(head));
            memset(belong, -1, sizeof(belong));
            memset(num, 0, sizeof(num));
            memset(res, -1, sizeof(res));
            memset(visit, 0, sizeof(visit));
            memset(in, 0, sizeof(in));
            memset(hd, -1, sizeof(hd));
            scanf("%d %d", &N, &M);
            for (i = 1; i <= M; i++)
            {
                scanf("%d %d", &p, &q);
                add(p, q);
            }
            solve(N, M, m);
        }
    }
    return 0;
}
void add(int x, int y)
{
    edge[cnt].from = x;
    edge[cnt].to = y;
    edge[cnt].next = head[x];
    head[x] = cnt++;
}
void ad(int x, int y)
{
    e[tot].to = y;
    e[tot].from = x;
    e[tot].next = hd[x];
    hd[x] = tot++;
}
void Tarjan(int f)
{
    int i, j, k, temp;
    low[f] = dfn[f] = ++Index;
    Stack[top++] = f;
    Instack[f] = 1;
    for (i = head[f]; i != -1; i = edge[i].next)
    {
        temp = edge[i].to;
        if (!dfn[temp])
        {
            Tarjan(temp);
            low[f] = (low[f] > low[temp]) ? low[temp] : low[f];
        }
        else if (Instack[temp] && low[f] > dfn[temp])
            low[f] = dfn[temp];
    }
    if (low[f] == dfn[f])
    {
        Sccc++;
        do
        {
            temp = Stack[--top];
            Instack[temp] = 0;
            num[Sccc]++;
            belong[temp] = Sccc;
        } while (temp != f);
    }
}
int dfs(int n)
{
    int i, j, k, t, sum = num[n];
    visit[n] = 1;
    for (i = hd[n]; i != -1; i = e[i].next)
        if (!visit[e[i].to])
            sum += dfs(e[i].to);
    return sum;
}
void solve(int n, int m, int cas)
{
    int i, j, k, s, t;
    for (i = 0; i < n; i++)
    {
        if (!dfn[i])
            Tarjan(i);
    }
    for (i = 0; i < n; i++)
    {
        for (j = head[i]; j != -1; j = edge[j].next)
        {
            if (belong[i] != belong[edge[j].to])
            {
                ad(belong[edge[j].to], belong[i]);
                in[belong[i]]++;
            }
        }
    }
    ans = -1;
    for (i = 1; i <= Sccc; i++)
    {
        if (!in[i])
        {
            memset(visit, 0, sizeof(visit));
            res[i] = dfs(i);
            if (ans < res[i])
                ans = res[i];
        }
    }
    printf("Case %d: %d\n", cas, ans-1);
    bool doudou = false;
    for (i = 0; i < n; i++)
        if (res[belong[i]] == ans)
        {
            if (doudou)
                putchar(' ');
            doudou = true;
            printf("%d", i);
        }
    putchar('\n');
}