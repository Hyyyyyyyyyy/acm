#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 100000000;
const int MIN = -100000000;
ll Min(ll a, ll b)
{
    if(a > b)
        return b;
    else
     return a;
}
struct node
{
    int index;
    ll val;
};
node ar[5];
bool comp(node a, node b)
{
    return a.val > b.val;
}
int main()
{
    ll i, j, k, u, n, m;
    ll ab, bc, ac, A, B, C, sum, D, T, I, J, K;
    while(scanf("%lld", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            sum = -1;
            scanf("%lld %lld %lld", &A, &B, &C);
            scanf("%lld %lld %lld", &ar[1].val, &ar[2].val, &ar[3].val);
            I = Min(A, B);
            J = Min(A, C);
            K = Min(B, C);
            for(i = 0; i <= I; i++)
            {
                for(j = 0; j <= J; j++)
                {
                    if(i+j > A)
                        continue;
                    for(k = 0; k <= K; k++)
                    {
                        if(i+j > A || i+k > B || j+k > C)
                            continue;
                        T = i*ar[1].val + j*ar[2].val + k*ar[3].val;
                        if(sum < T)
                            sum = T;
                    }
                }
            }
            printf("%I64d\n", sum);
        }
    }
    return 0;
}
