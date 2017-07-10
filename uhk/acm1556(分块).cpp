#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 100000 + 100;
int block_res[maxn], block_id[maxn], block_len;
int block_visit[maxn];
int ar[maxn];
void init(int n)
{
    int i, j;
    memset(ar, 0, sizeof(ar));
    memset(block_res, 0, sizeof(block_res));
    memset(block_visit, 0, sizeof(block_visit));
    block_len = sqrt(n);
    for (i = 1; i <= n; i++)
    {
        int u = i / block_len;
        block_id[i] = u;
    }
}
void update(int begin, int end)
{
    int i, j;
    for (i = begin; i <= end;)
    {
        if (i % block_len == 0 && i + block_len - 1 <= end)
        {
            block_visit[block_id[i]] += 1;
            i += block_len;
        }
        else
        {
            ar[i] += 1;
            i++;
        }
    }
}
int main()
{
    int i, j, k, u, n, m, a, b;
    while (scanf("%d", &n) != EOF && n)
    {
        init(n);
        for (i = 1; i <= n; i++)
        {
            scanf("%d %d", &a, &b);
            update(a, b);
        }
        for (i = 1; i <= n; i++)
        {
            if (i != 1)
                putchar(' ');
            printf("%d", ar[i] + block_visit[block_id[i]]);
        }
        putchar('\n');
    }
    return 0;
}