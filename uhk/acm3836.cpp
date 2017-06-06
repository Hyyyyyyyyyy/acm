#include <cstdio>
#include <cstring>
using namespace std;
int dfn[20010], low[20010];
int Instack[20010], Stack[20010];
int head[20010], belong[20010];
int in[50010], out[50010];
int top, Index, Sccc, IN, OUT, cnt;
struct node
{
    int from;
    int to;
    int next;
};
node edge[50010];
void addedge(int x, int y);
void solve(int n, int m);
void Tarjan(int f);
int main()
{
    int i, j, k, n, m, a, b;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        top = Index = Sccc = cnt = IN = OUT = 0;
        memset(Instack, 0, sizeof(Instack));
        memset(head, -1, sizeof(head));
        memset(dfn, 0, sizeof(dfn));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        memset(belong, -1, sizeof(belong));
        for (i = 1; i <= m; i++)
        {
            scanf("%d %d", &a, &b);
            addedge(a, b);
        }
        solve(n, m);
    }
    return 0;
}
void addedge(int x, int y)
{
    edge[cnt].from = x;
    edge[cnt].to = y;
    edge[cnt].next = head[x];
    head[x] = cnt++;
}
void Tarjan(int f)
{
    int i, j, temp;
    low[f] = dfn[f] = ++Index;
    Instack[f] = 1;
    Stack[top++] = f;
    for (i = head[f]; i != -1; i = edge[i].next)
    {
        temp = edge[i].to;
        if (!dfn[temp])
        {
            Tarjan(temp);
            if (low[f] > low[temp])
                low[f] = low[temp];
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
            belong[temp] = Sccc;
        } while (temp != f);
    }
}
void solve(int n, int m)
{
    int i, j, k, sum, t;
    for (i = 1; i <= n; i++)
        if (!dfn[i])
            Tarjan(i);
    for (i = 1; i <= n; i++)
    {
        for (j = head[i]; j != -1; j = edge[j].next)
        {
            t = edge[j].to;
            if (belong[i] != belong[t])
            {
                in[belong[t]]++;
                out[belong[i]]++;
            }
        }
    }
    for (i = 1; i <= Sccc; i++)
    {
        if (!in[i])
            IN++;
        if (!out[i])
            OUT++;
    }
    if (Sccc == 1)
        printf("0\n");
    else
        printf("%d\n", IN > OUT ? IN : OUT);
}