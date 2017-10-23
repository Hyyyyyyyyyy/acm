#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e9 + 7;
const int maxn = 2020;
int main()
{
	ll i, j, n, m, A, B;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld %lld", &A, &B);
			printf("Case #%lld:\n", m);
			if (A == B)
			{
				printf("1\n%lld %lld\n", A, B);
			}
			else
			{
				printf("2\n%lld %lld\n%lld %lld\n", A, B, B, A);
			}
		}
	}
	return 0;
}