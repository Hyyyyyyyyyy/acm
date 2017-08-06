#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 2147483640;
const int maxn = 1000000;
bool check[maxn + 10];
int prime[maxn + 10];
int mu[maxn + 10];
void Moblus()
{
    memset(check, false, sizeof(check));
    mu[1] = 1;
    int tot = 0;
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
}
//质数个数 < tot