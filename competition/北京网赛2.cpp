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
const int INF = 100000000;
const int MOD = 998244353;
const int maxn = 2000 + 500;
int ar[maxn];
struct Point
{
    int x;
    int y;
};
Point point[110];
bool check(int a1, int a2, int b1, int b2)
{
    int PX = point[a1].x - point[a2].x;
    int PY = point[a1].y - point[a2].y;
    int QX1 = point[b1].x - point[a2].x;
    int QY1 = point[b1].y - point[a2].y;
    int QX2 = point[b2].x - point[a2].x;
    int QY2 = point[b2].y - point[a2].y;
    if( (QX1*PY-PX*QY1) * (PX*QY2-QX2*PY) <= 0)
        return true;
    else
        return false;
}
int main()
{
    int i, j, k, u, n, m;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &N);
            for(i = 1; i <= N; i++)
            {
                scanf("%d %d", &point[i].x, &point[i].y);
            }
            bool doudou = false;
            for(i = 1; i <= N; i++)
            {
                for(j = 1; j <= N; j++)
                {
                    if(i == j)
                        continue;
                    for(p = 1; p <= N; p++)
                    {
                        for(q = 1; q <= N; q++)
                        {
                            if(p == q)
                                continue;
                            if(check(i, j, p, q))
                            {
                                doudou = true;
                                break;
                            }
                        }
                        if(doudou)
                            break;
                    }
                    if(doudou)
                        break;
                }
                if(doudou)
                    break;
            }
            if(doudou)
            {
                printf("YES\n");
                for(x = 1; x <= N; x++)
                {
                    if(x == i || x == j)
                        printf("B");
                    else
                        printf("A");
                }
                putchar('\n');
            }
            else
                printf("NO\n");
        }
    }
    return 0;
}