#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int Stack[100010], Instack[100010];
int dfn[100010], low[100010];
int head[100010];
int num[100010];
int Sccc, cnt, top, Index;
struct point
{
    int to;
    int next;
};
point edge[100010];
void addedge(int t, int n);
bool solve(int n);
void Tarjan(int f);
int main()
{
    int i, j, k, n, m, a, b, doudou;
    while (scanf("%d %d", &n, &m) != EOF && (n || m))
    {
        Sccc = 0;
        cnt = 0;
        top = 0;
        Index = 0;
        memset(head, -1, sizeof(head));
        memset(Instack, 0, sizeof(Instack));
        memset(dfn, 0, sizeof(dfn));
        memset(num, 0, sizeof(num));
        for (i = 1; i <= m; i++)
        {
            scanf("%d %d", &a, &b);
            addedge(a, b);
        }
        if (solve(n))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
void addedge(int a, int b)
{
    edge[cnt].to = b;
    edge[cnt].next = head[a];
    head[a] = cnt++;
}
bool solve(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        if (!dfn[i])
            Tarjan(i);
        if (num[i] == n)
            return true;
    }
    return false;
}
void Tarjan(int f)
{
    int i, k, j, temp;
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
        Sccc = f;
        do
        {
            temp = Stack[--top];
            Instack[temp] = 0;
            num[Sccc]++;
        } while (temp != f);
    }
}