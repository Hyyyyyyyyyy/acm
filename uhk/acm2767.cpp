#include <cstdio>
#include <cstring>
using namespace std;
struct node
{
    int from;
    int to;
    int next;
};
node edge[50010];
int Stack[20010], Instack[20010];
int dfn[20010], low[20010];
int head[20010];
int belong[20010];
int in[20010], out[20010];
int Sccc, top, Index, cnt;
int IN, OUT;
void add(int x, int y);
void Tarjan(int f);
void solve(int n, int m);
int main()
{
    int i, j, k, n, m, a, b, p, q;
    while (scanf("%d", &n) != EOF)
    {
        for (m = 1; m <= n; m++)
        {
            Sccc = top = Index = cnt = IN = OUT = 0;
            memset(head, -1, sizeof(head));
            memset(Instack, 0, sizeof(Instack));
            memset(dfn, 0, sizeof(dfn));
            memset(in, 0, sizeof(in));
            memset(out, 0, sizeof(out));
            memset(belong, -1, sizeof(belong));
            scanf("%d %d", &a, &b);
            for (i = 1; i <= b; i++)
            {
                scanf("%d %d", &p, &q);
                add(p, q);
            }
            solve(a, b);
            if (Sccc == 1)
                printf("0\n");
            else
            {
                printf("%d\n", IN > OUT ? IN : OUT);
            }
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
void solve(int n, int m)
{
    int i, j, k;
    for (i = 1; i <= n; i++)
        if (!dfn[i])
            Tarjan(i);
    for (i = 0; i < cnt; i++)
    {
        if (belong[edge[i].from] != belong[edge[i].to])
        {
            in[belong[edge[i].to]]++;
            out[belong[edge[i].from]]++;
        }
    }
    for (i = 1; i <= Sccc; i++)
    {
        if (in[i] == 0)
            IN++;
        if (out[i] == 0)
            OUT++;
    }
}
void Tarjan(int f)
{
    int i, j, temp;
    low[f] = dfn[f] = ++Index;
    Stack[top++] = f;
    Instack[f] = 1;
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