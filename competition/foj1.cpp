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
ll Max(ll a, ll b, ll c)
{
    if(a > b)
    {
        if(a > c)
            return a;
        else
         return c;
    }
    else
    {
        if(b > c)
            return b;
        else
            return c;
    }
}
struct node
{
    int index;
    int num;
    ll val;
};
node ar[5];
bool comp(node a, node b)
{
    if(a.val != b. val)
        return a.val > b.val;
    else
        return a.num > b.num;
}
int main()
{
    int i, j, k, u, n, m;
    ll ab, bc, ac, A, B, C, sum, D, T;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            sum = 0;
            scanf("%lld %lld %lld", &A, &B, &C);
            scanf("%lld %lld %lld", &ar[1].val, &ar[2].val, &ar[3].val);
            I = Min(A, B);
            J = Min(A, C);
            K = Min(B, C);
            if(Max(ar[1].val, ar[2].val, ar[3].val) == ar[1].val)
            {
                for(i = 1; i <= I; i++)
                {
                    for(j = 1; j <= J; j++)
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
            }
            if(Max(ar[1].val, ar[2].val, ar[3].val) == ar[2].val)
            {
                for(j = 1; j <= J; j++)
                {
                    for(k = 1; k <= K; k++)
                    {
                        if(j+k > C)
                            continue;
                        for(i = 0; i <= I; i++)
                        {
                            if(i+j > A || i+k > B || j+k > C)
                                continue;
                            T = i*ar[1].val + j*ar[2].val + k*ar[3].val;
                            if(sum < T)
                                sum = T;
                        }
                    }
                }
            }
            else
            {
                if(B < C)
                {
                    sum += ar[1].val * B;
                    C -= B;
                    if(ar[2].index == 2)
                    {
                        sum += ar[2].val * Min(A, C);
                    }
                    else
                    {
                        sum += ar[3].val * Min(A, C);
                    }
                }
                else
                {
                    sum += ar[1].val * C;
                    B -= C;
                    if(ar[2].index == 1)
                    {
                        sum += ar[2].val * Min(A, B);
                    }
                    else
                    {
                        sum += ar[3].val * Min(A, B);
                    }
                }
            }
            printf("%I64d\n", sum);
        }
    }
    return 0;
}