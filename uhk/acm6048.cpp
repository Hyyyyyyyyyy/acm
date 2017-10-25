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
const int maxn = 1500000 + 100;
int main()
{
	int i, j, k, u, n, m, N, M, P;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d %d", &N, &M, &P);
			int now = N * M - 1;
			int cnt = 0;
			while (now > P)
			{
				int tmp = (now - 1) / P + 1;
				cnt += (tmp - 1) * tmp / 2 * (P - 1);
				now -= tmp;
			}
			if (cnt & 1)
				puts("NO");
			else
				puts("YES");
		}
	}
	return 0;
}