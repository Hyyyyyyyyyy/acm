#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long int ll;
int main()
{
    ll i, j, k, u, n, m, p, q, count;
    while(scanf("%lld", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%lld %lld", &p, &q);
            count = 2;
            for(i = 2; i*i < p; i++)
            {
                if(p % i == 0)
                {
                    count += 2;
                }
            }
            if(i * i == p)
            {
                count++;
            }
            if(count == q)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
