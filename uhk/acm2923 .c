#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#define MAX 999999999
using namespace std;

int n, c, r;
map<string, int> ar;
int dist[1100][1100];
char sa[1100][110];
void floyd();
int main()
{
    int i, j, k, u, sum, count, cas = 1, d, x, y;
    char a[110], b[110], f, g;
    while (scanf("%d %d %d", &n, &c, &r) != EOF && (n || c || r))
    {
        ar.clear();
        sum = 0;
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= n; j++)
            {
                dist[i][j] = MAX;
            }
        }
        for (i = 0; i <= c; i++)
        {
            scanf("%s", sa[i]);
        }
        count = 1;
        for (i = 0; i < r; i++)
        {
            scanf("%s %c-%d-%c %s", a, &f, &d, &g, b);
            if (!ar[a])
                ar[a] = count++;
            x = ar[a];
            if (!ar[b])
                ar[b] = count++;
            y = ar[b];
            if (f == '<' && d < dist[y][x])
                dist[y][x] = d;
            if (g == '>' && d < dist[x][y])
                dist[x][y] = d;
        }
        floyd();
        //for (i = 1; i <= n; i++)
        //{
        //    for (j = 1; j <= n; j++)
        //    {
        //        printf("%d ", dist[i][j]);
        //    }
        //    putchar('\n');
        //}
        for (i = 1; i <= c; i++)
            sum += dist[ar[sa[0]]][ar[sa[i]]] + dist[ar[sa[i]]][ar[sa[0]]];
        printf("%d. %d\n", cas++, sum);
    }
    return 0;
}
void floyd()
{
    int i, j, k;
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}