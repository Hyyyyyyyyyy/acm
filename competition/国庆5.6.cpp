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
ll N;
ll Pow[31];
char s[50];
int main()
{
	ll i, j, k, n, m;
	Pow[0] = 1ll;
	for (i = 1; i <= 30; i++)
		Pow[i] = Pow[i - 1] * 2ll;
	while (scanf("%s", s) != EOF)
	{
		ll L = strlen(s);
		ll X = Pow[L];
		ll Y = Pow[L];
		printf("%lld ", L);
		for (i = 0; i < L; i++)
		{
			if (s[i] == '0')
			{
				X -= Pow[L - i-1];
				Y -= Pow[L - i-1];
			}
			else if (s[i] == '1')
			{
				X -= Pow[L - i-1];
			}
			else if (s[i] == '2')
			{
				Y -= Pow[L - i-1];
			}
		}
		printf("%lld %lld\n", Y-1, X-1);
	}
	return 0;
}