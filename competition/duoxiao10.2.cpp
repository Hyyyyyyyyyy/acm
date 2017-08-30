#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
const int INF = 2147483640;
const double eps = 1e-7;
typedef long long ll;
const ll MOD = 998244353ll;
const int maxn = 100000+100;
int cnt;
int K[maxn];
int MK[maxn];
struct Node
{
    int v;
    int f;
};
Node ar[maxn], stack[maxn];
bool comp(Nde& a, Node& b)
{
    return a.v < b.v;
}
int main()
{
    int i, j, k, u, n, m, a, b;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &N);
            cnt = 0;
            memset(K, 0, sizeof(K));
            for(i = 1; i <= N; i++)
            {
                scanf("%d %d", &a, &b);
                ar[++cnt].v = a;
                ar[cnt].f = 1;
                ar[++cnt].v = b;
                ar[cnt].f = 2;
            }
            sort(ar+1, ar+1+cnt, comp);
            ll res = 0;
            ll Max = 0;
            for(i = 1; i <= cnt; i++)
            {
                if(ar[i].f == 1)
                    K[i]++;
                if(ar[i].f == 2)
                    K[i]--;
                if(Max < K[i])
                    Max = K[i];
            }
            MK[cnt] = 0;
            for(i = cnt-1; i >= 1; i--)
            {
                MK[i] = max(K[i], MK[i]);
            }
            for(i = 2; i <= cnt; i++)
            {
                res += (ar[i].v - ar[i-1].v) * MK[i-1];
            }
            printf("%lld %lld\n", Max, res);
        }
    }
    return 0;
}