#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 2147483640;
const int maxn = 500100;
bool check[maxn + 10];
int prime[maxn + 10];
int mu[maxn + 10];
ll mob[maxn][20];
ll cnt[maxn];
void Moblus()
{
    memset(check, false, sizeof(check));
    memset(cnt, 0, sizeof(cnt));
    mu[1] = 1;
    int tot = 0;
    for(int i = 2; i <= maxn; i++)
    {
        if(!check[i])
        {
            prime[tot++] = i;
            mu[i] = -1;
            cnt[i] = 1;
        }
        for(int j = 0; j < tot; j++)
        {
            if(i * prime[j] > maxn)
                break;
            check[i * prime[j]] = true;
            cnt[i * prime[j]] = cnt[i] + 1;
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
}
void init()
{
    Moblus();
    memset(mob, 0, sizeof(mob));
    for(int i = 1; i < maxn; i++)
    {
        for(int j = i; j < maxn; j += i)
        {
            mob[j][cnt[i]] += (ll)mu[j / i];
        }
    }
    for(int i = 1; i < maxn; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            mob[i][j] += mob[i-1][j];
        }
    }
    for(int i = 0; i < maxn; i++)
    {
        for(int j = 1; j < 19; j++)
        {
            mob[i][j] += mob[i][j-1];
        }
    }
}

int N, M, P;
int main()
{
    int i, j, k, u, n, m;
    init();
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d %d", &N, &M, &P);
            if(P >= 19)
            {
                printf("%lld\n", (ll)N * (ll)M);
                continue;
            }
            if(N > M)
                swap(N, M);
            ll res = 0;
            for(i = 1, j = 1; i < N; i = j + 1)
            {
                j = min(N / (N / i), M / (M / i));
                res += (mob[j][P] - mob[i-1][P]) * ((ll)N / (ll)i) * ((ll)M / (ll)i);
            }
            printf("%lld\n", res);
        }
    }
    return 0;
}
