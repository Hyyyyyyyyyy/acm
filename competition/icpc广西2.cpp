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
const int maxn = 100000 + 100;
ll ar[maxn];
// bool visit[maxn];
ll sa[maxn];
int N, Q, p;
ll A, B, C;
int main()
{
    int i, j, k, u, n, m;
    while(scanf("%d %d", &N, &Q) != EOF)
    {
        memset(sa, 0, sizeof(sa));
        memset(visit, false, sizeof(visit));
        scanf("%lld", &ar[1]);
        A = B = C = ar[1];
        for(i = 2; i <= N; i++)
        {
            scanf("%lld", &ar[i]);
            ll t = ar[i];
            while(t)
            {
                sa[i] <<= 1;
                if((t & 1) == 0)
                {
                    sa[i] |= 1;
                }
                t >>= 1;
            }
            A &= ar[i];
            B |= ar[i];
            C ^= ar[i];
        }
        for(i = 1; i <= Q; i++)
        {
            scanf("%d", &p);
            printf("%lld %lld %lld\n", A | sa[p], B & sa[p], C ^ ar[p]);
        }
    }
    return 0;
}