#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cctype>
#include <set>
using namespace std;
const int INF = 1e10;
const double eps = 1e-8;
typedef long long ll;
const int maxn = 10010;
int N;
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			int cnt = 0;
			while (N)
			{
				N >>= 1;
				cnt++;
			}
			printf("Case %d: %d\n", m, cnt);
		}
	}
	return 0;
}