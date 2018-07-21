#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
#define retrun return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 1000000 + 100;
const int maxm = 1000000 + 100;
ll N;
ll cal(ll k, ll r)
{
	ll sum = 0;
	ll p = 1;
	for (ll i = 1; i <= r; i++)
	{
		if (N / p < k)
			return N + 1;
		p *= k;
		sum += p;
		if (sum > N)
			return sum;
	}
	return sum;
}
ll search(ll r)
{
	ll L = 2;
	ll R = N;
	ll mid;
	while (L <= R)
	{
		mid = (L + R) / 2;
		ll temp = cal(mid, r);
		if (temp == N || temp == N - 1)
			return mid;
		if (temp > N)
		{
			R = mid - 1;
		}
		else
			L = mid + 1;
	}
	return -1;
}
int main()
{
	ll i, j, k, r;
	while (scanf("%lld", &N) != EOF)
	{
		ll L, R;
		ll res = INF;
		ll resi = INF;
		ll resj = INF;
		for (j = 1; j <= 45; j++)
		{
			k = search(j);
			if (k != -1 && res > j*k)
			{
				res = k * j;
				resi = k;
				resj = j;
			}
		}
		printf("%lld %lld\n", resj, resi);
	}
	return 0;
}

//预估r的取值范围1~40 枚举r，二分查找k
//注意k的r次方会溢出，不要用等比数列求和公式+快速幂