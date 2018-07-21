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
int main()
{
	int i, j, k;
	ll N;
	while (scanf("%lld", &N) != EOF && N)
	{
		printf("%lld: ", N);
		ll p = 1;
		ll res = 0;
		while (N)
		{
			ll u = N % 10;
			if (u > 8)
				u -= 2;
			else if (u > 3)
				u -= 1;
			res += u * p;
			p *= 8;
			N /= 10;
		}
		printf("%lld\n", res);
	}
	return 0;
}