#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 1e9+1;
const int maxn = 50 + 100;
int N, M;
int ar[maxn][maxn];
int sa[maxn][maxn];
struct Node
{
    int x;
    int y;
};
Node res[maxn];
int topres;
bool comp(const Node& a, cost Node& b)
{
    if(a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}
int main()
{
    int i, j, k,u, n, m, a, b;
    while(sacnf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d", &N, &M);
            memset(ar, 0, sizeof(ar));
            memset(sa, 0 ,sizeof(sa));
            topres = 0;
            for(i = 1; i <= N; i++)
            {
                scanf("%d %d", &a, &b);
                ar[b][++ar[b][0]] = a;
            }
            for(i = 1; i <= M; i++)
            {
                scanf("%d %d", &a, &b);
                for(j = 1; j <= ar[a][0]; j++)
                {
                    res[++topres].x = ar[a][j];
                    res[topres].y = b;
                }
            }
            sort(res+1, res + 1 + topres, comp);
            printf("%d %d\n", res[1].x, res[1].y);
            for(i = 2; i <= topres; i++)
            {
                if(res[i].x == res[i-1].x && res[i].y == res[i-1].y)
                    continue;
                printf("%d %d\n", res[i].x, res[i].y);
            }
        }
    }
    return 0;
}