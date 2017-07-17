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
const int INF = 2147483640;
const int maxn = 200;
int main()
{
	int i, j, k, u, n, m, a, b, c, x, y, z, N, M;
	while (scanf("%d", &N) != EOF)
	{
		for (M = 1; M <= N; M++)
		{
			scanf("%d %d %d %d %d %d", &n, &x, &y, &z, &a, &b);
			int A = (z - 1) * a + abs(y - 0) + abs(x - 0);
			int B = (z - 1) * b + 2 * n + abs(y - n) + abs(x - n);
			printf("%d\n", A < B ? A : B);
		}
	}
	return 0;
}