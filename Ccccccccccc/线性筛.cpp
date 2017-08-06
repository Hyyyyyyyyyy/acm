#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 2147483640;
const int maxn = 10000000;
bool check[maxn + 10];
int prime[maxn + 10];
int phi[maxn + 10];
int tot;
void phi_and_prime_table(int N)
{
    memset(check, false, sizeof(check));
    phi[1] = 1;
    tot = 0;
    for(int i = 2; i <= N; i++)
    {
        if(!check[i])
        {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; j < tot; j++)
        {
            if(i * prime[j] > N)
                break;
            check[i * prime[j]] = true;
            if(i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
            {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
}
//质数个数 < tot