#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef unsigned long long ll;
const double eps = 1e-8;
const int INF = 2147483640;
const int maxn = 100000 + 100;
int main()
{
	ll i, j, k, u, n, m, N, doudou;
	while (scanf("%llu", &N) != EOF)
	{
		ll res = 0;
		doudou = 1;
		for (i = 1; i <= N; i++)
		{
			ll tt = i;
			ll t = 1;
			for (j = 1; j <= i; j++)
			{
				t *= tt;
				if (t > N)
				{
					doudou = 0;
					break;
				}
			}
			if (doudou == 0)
				break;
			else
				res++;
		}
		printf("%llu\n", res);
	}
	return 0;
}