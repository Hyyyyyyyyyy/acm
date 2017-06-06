#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
typedef long long ll;
int main()
{
	ll i, j, k, u, n, m, res, a;
	ll sum;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld", &a);
			ll res = 0;
			for (i = 1; i < a; i++)
			{
				sum = 0;
				for (j = 2; j < a; j++)
				{
					sum = (i + i + j - 1) * j / 2;
					if (sum > a)
						break;
					if (sum == a)
						res++;
				}
			}
			printf("Case %lld: %lld\n", m, res);
		}
	}
	return 0;
}