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
typedef long long ll;
const double eps = 1e-8;
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
int main()
{
	ll i, j, k, u, n, m, N;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld", &N);
			ll T = sqrt(N);
			bool doudou = false;
			for (i = 0; i <= T; i++)
			{
				if (3*i*i + 3*i + 1 == N)
				{
					doudou = true;
					break;
				}
			}
			if (doudou)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}