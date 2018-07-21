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
const int maxn = 200000 + 100;
const int maxm = 1000000 + 100;
ll power[40];
ll ar[maxn];
int main()
{
	int i, j, k, N;
	power[0] = 1;
	for (i = 1; i <= 31; i++)
	{
		power[i] = power[i - 1] * 2ll;
	}
	while (scanf("%d", &N) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
		}
		sort(ar + 1, ar + 1 + N);
		int res = 0;
		for (i = 1; i <= N; i++)
		{
			int doudou = 0;
			for (j = 0; j <= 30; j++)
			{
				ll x = power[j] - ar[i];
				if (x <= 0)
					continue;
				int pos = lower_bound(ar + 1, ar + 1 + N, x) - ar;
				if (ar[pos] == x)
				{
					if (pos == i)
					{
						if (ar[i - 1] == ar[i] || ar[i + 1] == ar[i])
						{
							doudou = 1;
							break;
						}
					}
					else
					{
						doudou = 1;
						break;
					}
				}
			}
			if (!doudou)
				res++;
		}
		printf("%d\n", res);
	}
	return 0;
}
//暴力加二分