#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll N, M;
int main()
{
    ll i, j, k;
    int cas = 1;
    while (scanf("%lld %lld", &N, &M) != EOF)
    {
        if (M - N <= 0)
        {
            printf("Case #%d: %lld\n", cas++, M);
            continue;
        }
        ll res = (M - N) % (2 * (N - 1));
        if (res <= (N - 1) && res > 0)
        {
            printf("Case #%d: %lld\n", cas++, res);
        }
        else
        {
            if (res == 0)
            {
                printf("Case #%d: %lld\n", cas++, N);
            }
            else
            {
                printf("Case #%d: %lld\n", cas++, res - (N - 1));
            }
        }
    }
    return 0;
}