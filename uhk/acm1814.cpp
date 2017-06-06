#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int head[40010];
int Stack[40010];
int cnt, top, n, m;
struct node
{
    int from;
    int to;
    int next;
};
node edge[40010];
int set[40010];
void addedge(int x, int y);
bool judge();
bool dfs(int n);
int main()
{
    int i, j, k, u, a, b, c;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        cnt = 0;
        memset(head, -1, sizeof(head));
        for (u = 1; u <= m; u++)
        {
            scanf("%d %d", &a, &b);
            a -= 1;
            b -= 1;
            addedge(a, b ^ 1);
            addedge(b, a ^ 1);
        }
        memset(set, 0, sizeof(set));
        if (judge())
        {
            for (i = 0; i < 2 * n; i++)
            {
                if (set[i])
                    printf("%d\n", i + 1);
            }
        }
        else
            printf("NIE\n");
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
bool judge()
{
    int i, j, k;
    for (i = 0; i < 2 * n; i++)
    {
        if (set[i] || set[i ^ 1])
            continue;
        top = 0;
        if (!dfs(i))
        {
            for (j = 0;j < top; j++)
                set[Stack[j]] = 0;
            top = 0;
            if (!dfs(i ^ 1))
                return false;
        }
    }
    return true;
}
bool dfs(int n)
{
    int i, j, k, t;
    if (set[n])
        return true;
    if (set[n ^ 1])
        return false;
    Stack[top++] = n;
    set[n] = 1;
    for (i = head[n]; i != -1; i = edge[i].next)
    {
        t = edge[i].to;
        if (!dfs(t))
        {
            return false;
        }
    }
    return true;
}