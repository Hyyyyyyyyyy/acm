#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
int ar[100000 * 4];
int sa[100000 * 4];
int visit[100000 * 4];
int lef[100000 * 4], rig[100000 * 4];
int N;
void build(int root, int begin, int end);
void update(int root, int begin, int end, int b, int e, int val);
void pushdown(int root);
int main()
{
    int i, j, k, u, n, m, a, b, c;
    while (scanf("%d", &n) != EOF)
    {
        for (m = 1; m <= n; m++)
        {
            scanf("%d", &N);
            build(1, 1, N);
            scanf("%d", &k);
            for (u = 1; u <= k; u++)
            {
                scanf("%d %d %d", &a, &b, &c);
                update(1, 1, N, a, b, c);
            }
            printf("Case %d: The total value of the hook is %d.\n", m, sa[1]);
        }
    }
    return 0;
}
void build(int root, int begin, int end)
{
    visit[root] = 0;
    lef[root] = begin;
    rig[root] = end;
    sa[root] = 0;
    if (begin == end)
        sa[root] = 1;
    else
    {
        build(root * 2, begin, (begin + end) / 2);
        build(root * 2 + 1, (begin + end) / 2+1, end);
        sa[root] = sa[root * 2] + sa[root * 2 + 1];
    }
}
void update(int root, int begin, int end, int b, int e, int val)
{
    if (begin > e || end < b)
        return;
    if (begin >= b && end <= e)
    {
        sa[root] = val*(rig[root] - lef[root] + 1);
        visit[root] = val;
        return;
    }
    pushdown(root);
    update(root * 2, begin, (begin + end) / 2, b, e, val);
    update(root * 2 + 1, (begin + end) / 2+1, end, b, e, val);
    sa[root] = sa[root * 2] + sa[root * 2 + 1];
}
void pushdown(int root)
{
    if (visit[root])
    {
        visit[root * 2] = visit[root];
        visit[root * 2 + 1] = visit[root];
        sa[root * 2] = visit[root] * (rig[root * 2] - lef[root * 2] + 1);
        sa[root * 2 + 1] = visit[root] * (rig[root * 2 + 1] - lef[root * 2 + 1] + 1);
        visit[root] = 0;
    }
}