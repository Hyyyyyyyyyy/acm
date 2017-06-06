#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
//const int max(int a, int b) { return (a > b) ? a : b; };
//const int min(int a, int b) { return (a < b) ? a : b; };
struct node
{
    int l;
    int r;
    int mid;
    int lx;
    int rx;
    int mx;
};
node edge[100000 * 4];
int ar[100010];
void build(int root, int begin, int end);
void update(int root, int begin, int end, int index, int val);
int query(int root, int begin, int end, int b, int e);
void pushup(int root);
int N, M;
int main()
{
    int i, j, k, u, n, m, a, b, c;
    char s[5];
    while (scanf("%d", &n) != EOF)
    {
        for (m = 1; m <= n; m++)
        {
            scanf("%d %d", &N, &M);
            for (i = 0; i < N; i++)
            {
                scanf("%d", &ar[i]);
            }
            build(1, 0, N - 1);
             //for(int i=1;i<=30;i++)  
             //  printf("%d %d %d %d %d\n",edge[i].l,edge[i].r,edge[i].mx,edge[i].lx,edge[i].rx);  
            for (u = 1; u <= M; u++)
            {
                scanf("%s%d%d", s, &a, &b);
                if (strcmp(s, "Q") == 0)
                {
                    printf("%d\n", query(1, 0, N - 1, a, b));
                }
                else
                {
                    ar[a] = b;
                    update(1, 0, N - 1, a, b);
                }
            }
        }
    }
    return 0;
}
void build(int root, int begin, int end)
{
    edge[root].l = begin;
    edge[root].r = end;
    edge[root].mid = (begin + end) / 2;
    if (begin == end)
    {
        edge[root].lx = edge[root].rx = edge[root].mx = 1;
    }
    else
    {
        build(root * 2, begin, edge[root].mid);
        build(root * 2 + 1, edge[root].mid + 1, end);
        pushup(root);
    }
}
void pushup(int root)
{
    edge[root].lx = edge[root * 2].lx + (((edge[root * 2].r - edge[root * 2].l + 1) == edge[root * 2].lx && ar[edge[root * 2].r] < ar[edge[root * 2 + 1].l]) ? (edge[root * 2 + 1].lx) : 0);
    edge[root].rx = edge[root * 2 + 1].rx + (((edge[root * 2 + 1].r - edge[root * 2 + 1].l + 1) == edge[root * 2 + 1].rx && ar[edge[root * 2 + 1].l] > ar[edge[root * 2].r]) ? (edge[root * 2].rx) : 0);
    edge[root].mx = max(max(edge[root * 2].mx, edge[root * 2 + 1].mx), (ar[edge[root * 2].r] < ar[edge[root * 2 + 1].l]) ? (edge[root * 2].rx + edge[root * 2 + 1].lx) : 0);
}
void update(int root, int begin, int end, int index, int val)
{
    if (begin == end)
    {
        edge[root].lx = edge[root].rx = edge[root].mx = 1;
    }
    else
    {
        if (index <= edge[root].mid)
            update(root * 2, begin, edge[root].mid, index, val);
        else
            update(root * 2 + 1, edge[root].mid + 1, end, index, val);
        pushup(root);
    }
}
int query(int root, int begin, int end, int b, int e)
{
    if (begin == b && end == e)
        return edge[root].mx;
    else if (e <= edge[root].mid)
        return query(root * 2, begin, edge[root].mid, b, e);
    else if (b > edge[root].mid)
        return query(root * 2 + 1, edge[root].mid + 1, end, b, e);
    else
    {
        int t1 = query(root * 2, begin, edge[root].mid, b, edge[root].mid);
        int t2 = query(root * 2 + 1, edge[root].mid + 1, end, edge[root].mid + 1, e);
        int res = 0;
        if (ar[edge[root * 2].r] < ar[edge[root * 2 + 1].l])
        {
            res = min(edge[root].mid - b + 1, edge[root * 2].rx) + min(e - edge[root].mid, edge[root * 2 + 1].lx);
        }
        return max(max(t1, t2), res);
    }
}