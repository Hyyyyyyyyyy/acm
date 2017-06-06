#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
using namespace std;
const double PI = acos(-1.0);
int main()
{
	int i, j, k, u, n, m, a, b, c, r[10010];
	double x, y, s[10010];
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &a, &b);
			b++;
			for (u = 1; u <= a; u++)
			{
				scanf("%d", &r[u]);
				s[u] = PI*r[u] * r[u];
			}
			sort(s + 1, s + a+1);
			double l = 0;
			double R = s[a];
			double mid = (R + l) / 2.0;
			int sum = 0;
			while (R - l > 1.0e-6)
			{
				for (i = 1; i <= a; i++)
				{
					sum = sum + (int)(s[i] / mid);
				}
				if (sum < b)
					R = mid;
				else
					l = mid;
				mid = (l + R) / 2.0;
				sum = 0;
			}
			printf("%.4lf\n", mid);
		}
	}
	return 0;
}
