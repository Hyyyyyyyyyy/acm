#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <queue>  
#include <cmath>  
#include <algorithm>  
#include <deque>  
using namespace std;
typedef long long ll;
const int INF = 2147483640;
const int maxn = 100000 + 100;
const int MOD = 1e9 + 7;
set<int>G[maxn];
int ar[maxn];
int prime[maxn + 1];
bool check[maxn + 10];
int Num[maxn+10];
int stack[maxn];
int tot;
void getprime()
{
    int i, j;
    memset(check, false, sizeof(check));
    memset(Num, 0, sizeof(Num));
    for (i = 2; i <= 100000; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            Num[i+1]++;
        }
        for (j = 0; j < tot; j++)
        {
            if (i * prime[j] > 100000)
                break;
            check[i * prime[j]] = true;
        }
    }
    for(i = 2; i <= 100000; i++)
        Num[i] += Num[i-1];
    //    for(i = 0; i < tot; i++)
    //        printf("%d\n", prime[i]);
    //    printf("%d\n", tot);
}
int main()
{
    int i, j, k, u, n, m, cas = 1, N;
    tot = 0;
    getprime();
    while (scanf("%d", &n) != EOF)
    {
        for (m = 1; m <= n; m++)
        {
            scanf("%d", &N);
            int Min = INF;
            for (i = 1; i <= N; i++)
            {
                scanf("%d", &ar[i]);
                Min = min(ar[i], Min);
            }
            ll ans = 0;
            for (i = 0; i < tot; i++)
            {
                if (prime[i] > Min)
                    break;
                ll res = 1;
                int top = 0;
                int mm = ar[i];
                for(j = 1; j <= N; j++)
                {
                    stack[++top] = ar[j] / prime[i];
                    mm = min(mm, stack[top]);
                }
                for (j = 1; j <= top; j++)
                {
                    res = (res * (stack[j] - mm)) % MOD;
                }
                ans = (ans + res) % MOD;
            }
            printf("Case #%d: %lld\n", cas++, ans);
        }
    }
    return 0;
}