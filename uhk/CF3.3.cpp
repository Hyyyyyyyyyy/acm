#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;
typedef __int64 ll;
const int MAX = 11;
ll N;
ll s;
ll solve(ll n);
bool check(ll n);
int main()
{
	int i, j, u, max, a, b;
	ll n, m, k, res;
	while (scanf("%I64d %I64d", &N, &s) != EOF)
	{
		printf("%I64d\n", solve(N));
	}
	return 0;
}
bool check(ll n)
{
	ll res = 0;
	ll t = n;
	while (n)
	{
		res += n % 10;
		n /= 10;
	}
	return (t - res) >= s;
}
ll solve(ll n)
{
	ll l = 1;
	ll r = N;
	ll mid;
	while (r >= l)
	{
		mid = (r + l) / 2;
		if (check(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	return N - l + 1;
}
