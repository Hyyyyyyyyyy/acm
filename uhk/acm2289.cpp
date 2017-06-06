#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;
const double PI = acos(-1.0);
int main()
{
	int i, j, k, n, m, u, a, b, c;
	double r, R, H, V;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lf %lf %lf %lf", &r, &R, &H, &V);
			double l = 0.0;
			double ri = H;
			double mid = (l + ri) / 2.0;
			while (ri - l >= 1.0e-9)
			{
				double rr = r + (R - r) * mid / H;
				double v = 1.0 / 3.0 * PI * mid * (r* r + rr*rr + r * rr);
				if (v <= V)
					l = mid;
				else
					ri = mid;
				mid = (l + ri) / 2.0;
			}
			printf("%.6lf\n", mid);
		}
	}
	return 0;
}
