#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
    int val;
    int to;
    int from;
};
node d[10001];
bool comp(node a, node b)
{
    return a.val < b.val;
}
int main()
{
    int i, j, k, u, n, m, a, b, c, ar[110][110], set[110], flag;
    long long sum;
    while (scanf("%d", &n) != EOF)
    {
        c = 0;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                scanf("%d", &ar[i][j]);
            }
        }
        scanf("%d", &k);
        for (u = 1; u <= k; u++)
        {
            scanf("%d %d", &a, &b);
            ar[a][b] = 0;
            ar[b][a] = 0;
        }
        for (i = 1; i <= n; i++)
        {
            for (j = i; j <= n; j++)
            {
                d[c].val = ar[i][j];
                d[c].from = i;
                d[c++].to = j;
            }
        }
        for (i = 0; i <= n; i++)
            set[i] = i;
        sum = 0;
        flag = 0;
        sort(d, d + c, comp);
        //for (i = 0; i < c; i++)
        //    printf("%d %d %d\n", d[i].val, d[i].from, d[i].to);
        for (i = 0; i < c; i++)
        {
            a = d[i].from;
            b = d[i].to;
            while (a != set[a])
                a = set[a];
            while (b != set[b])
                b = set[b];
            if (a != b)
            {
                set[b] = a;
                sum += d[i].val;
                flag++;
            }
            if (flag == n - 1)
            {
                printf("%lld\n", sum);
                break;
            }
        }
    }
    return 0;
}