#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
const int INF = 2147483640;
const double eps = 1e-7;
typedef unsigned long long ll;
const int maxn = 500000 + 10;
const ll MOD = 998244353;
int main()
{
	int i, j, k, u, n, m;
	while(scanf("%d", &n) != EOF)
	{
		int cnt = 0;
		for(i = 1; i <= n; i++)
		{
			scanf("%d", &u);
			if(u <= 35)
			{
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
