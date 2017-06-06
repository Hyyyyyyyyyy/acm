#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int i, j, k, u, n, m;
	double x, Y, z;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lf", &Y);
			double l = 0;
			double r = 100;
			double mid = (l + r) / 2.0;
			while (r - l > 1e-6)
			{
				if (42 * pow(mid, 6.0) + 48 * pow(mid, 5.0) + 21 * pow(mid, 2.0) + 10 * mid < Y)
				{
					l = mid;
				}
				else
				{
					r = mid;
				}
				mid = (l + r) / 2.0;
			}
			printf("%.4lf\n", 6 * pow(mid, 7.0) + 8 * pow(mid, 6.0) + 7 * pow(mid, 3.0) + 5 * pow(mid, 2.0) - Y*mid);
		}
	}
	return 0;
}