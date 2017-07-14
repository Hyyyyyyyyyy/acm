#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 500000 + 100;
const double eps = 1e-3;
int N;
int main()
{
	int i, j, k, u, n, m, a, b, c;
	double s;
	while (scanf("%d", &N) != EOF)
	{
		int cnt = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			if (a < 60 || b < 60 || c < 60)
			{
				continue;
			}
			s = (1.0 * (a + b + c) / 10 - 15);
			if (s >= 9.0)
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}