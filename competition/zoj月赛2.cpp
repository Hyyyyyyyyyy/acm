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
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 100000007ll;
const int maxn = 100000 + 100;
const int maxm = 100000 + 100;
ll A[maxn], B[maxn];
int main()
{
	ll i, j, k, CAS, cas, N;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &A[i]);
			}
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &B[i]);
			}
			sort(B + 1, B + 1 + N);
			ll doudou = 0;
			for (i = 1; i <= N; i++)
			{
				ll l = 1;
				ll r = N;
				ll mid;
				while (l <= r)
				{
					mid = (l + r) / 2;
					if (A[i] < B[mid])
						r = mid - 1;
					else if (A[i] > B[mid])
						l = mid + 1;
					else
					{
						printf("%lld\n", A[i]);
						doudou = 1;
						break;
					}
				}
				if (doudou)
					break;
			}
		}
	}
	return 0;
}