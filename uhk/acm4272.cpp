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
const int maxn = 1000 + 100;
const int maxm = 1000000 + 100;
ll ar[maxn];
int main()
{
	int i, j, k, cas, CAS, N;
	while (scanf("%d", &N) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%lld", &ar[i]);
		}
		int doudou = 1;
		for (i = 1; i <= N; i++)
		{
			if (ar[i] == -1)
				continue;
			int step = 0;
			for (j = i + 1; j <= N; j++)
			{
				if (ar[j] == -1)
					continue;
				if (step > 6)
				{
					doudou = 0;
					break;
				}
				step++;
				if (ar[i] == ar[j])
				{
					ar[i] = ar[j] = -1;
					break;
				}
			}
			if (j > N)
				doudou = 0;
			if (!doudou)
				break;
		}
		printf("%d\n", doudou);
	}
	return 0;
}