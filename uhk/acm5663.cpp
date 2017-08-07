#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 2147483640;
const int maxn = 10000000 + 10;
const ll MOD = 258280327;
bool check[maxn + 10];
int prime[maxn + 10];
int mu[maxn + 10];
ll ar[maxn+10];
int d[maxn+10];
void Moblus()
{
    memset(check, false, sizeof(check));
    mu[1] = 1;
    int tot = 0;
    int num = 0;
    for(int i = 2; i <= maxn; i++)
    {
        if(!check[i])
        {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot; j++)
        {
            if(i * prime[j] > maxn)
                break;
            check[i * prime[j]] = true;
            if(i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    for(int i = 1; i <= maxn; i++)
    {
        int t = (int)sqrt(i * 1.0);
        if(t * t == i)
            d[++num] = i;
    }
    for(int i = 1; i <= num; i++)
    {
        int p = d[i];
        for(int j = 1; j * p <= maxn; j++)
        {
            ar[j*p] += mu[j];
        }
    }
    for(int i = 1; i <= maxn; i++)
        ar[i] += ar[i - 1];
}
//???? < tot
int main()
{
    int i, j, k, u, n, m;
    Moblus();
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            int N, M;
            scanf("%d %d", &N, &M);
            if(N > M)
                swap(N, M);
            ll res = 0;
            for(int i = 1, j = 0; i <= N; i = j + 1)
            {
                j = min(N / (N / i), M / (M / i));
                res += (ar[j] - ar[i-1]) * ((ll)N / (ll)i) * ((ll)M / (ll)i);
            }
            printf("%lld\n", (ll)N * (ll)M - res);
        }
    }
    return 0;
}