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
const int inf = 1e8;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 100 + 100;
const int maxm = 1000000 + 100;
ll N;
ll pow2[60];
ll pow3[60];
int main()
{
	ll i, j, k, cas, CAS;
	pow2[0] = 1;
	pow3[0] = 1;
	for (i = 1; i <= 50; i++)
	{
		pow2[i] = pow2[i - 1] * 2;
	}
	for (i = 1; i <= 50; i++)
	{
		pow3[i] = pow3[i - 1] * 3;
	}
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld", &N);
			if (N == 2 || N == 3)
			{
				printf("1\n");
				continue;
			}
			N -= 2;
			ll res = 0;
			for (i = 0; i <= 50; i++)
			{
				for (j = 0; j <= 50; j++)
				{
					if (i * 2 + j * 3 == N)
					{
						res = max(res, pow2[i] * pow3[j]);
					}
				}
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}