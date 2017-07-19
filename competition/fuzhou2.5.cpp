#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cctype>
#include <set>
using namespace std;
const int INF = 1e10;
const double eps = 1e-8;
typedef long long ll;
const int maxn = 10000+100;
int ar[maxn], sa[maxn];
int N;
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
                scanf("%d", &ar[i]);
            }
            for(i = 1; i <= N; i++)
            {
                scanf("%d", &sa[i]);
            }
            int res = 0;
            for(i = 1; i <= N; i++)
            {
                if(ar[i] + sa[i] > 10)
                    res++;
            }
            printf("Case %d: %d\n", m, res);
        }
    }
    return 0;
}