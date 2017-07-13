#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 150;
const double eps = 1e-8;
const int INF = 1e9;
typedef long long ll;
const double PI = acos(-1.0);
int main()
{
	int i, j, n, m;
	double cx, cy, R, x1, y1, x2, y2;
	double k, c, a, b, A, B, C, DT, X1, X2, dis, Y1, Y2;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lf %lf %lf %lf %lf %lf %lf", &cx, &cy, &R, &x1, &y1, &x2, &y2);
			if (fabs(x1 - x2) < eps)
			{
				dis = fabs(x1 - cx);
				if (dis >= R)
					printf("All out\n");
				else
				{
					Y1 = cy + sqrt(R*R - (x1 - cx) * (x1 - cx));
					Y2 = cy - sqrt(R*R - (x1 - cx) * (x1 - cx));
					if ((y1 <= Y2 && y2 <= Y2) || (y1 >= Y1 && y2 >= Y1))
						printf("All out\n");
					else if (Y2 <= y1 && y1 <= Y1 && Y2 <= y2 && y2 <= Y1)
						printf("All in\n");
					else
						printf("Part in\n");
				}
				continue;
			}
			k = (y2 - y1) / (x2 - x1);
			c = y1 - k*x1;
			a = cx;
			b = cy;
			A = k*k + 1;
			B = 2 * (k * c - k * b - a);
			C = a*a + (c - b) * (c - b) - R*R;
			DT = sqrt(B * B - 4.0 * A * C);
			X1 = (-B + DT) / (2.0 * A);
			X2 = (-B - DT) / (2.0 * A);
			dis = fabs(k * a - b + c) / sqrt(k * k + 1);
			if (dis - R > eps)
			{
				printf("All out\n");
			}
			else
			{
				if ((X1 <= x1  && X1 <= x2 ) || (x1 <= X2  && x2 <= X2))
				{
					printf("All out\n");
				}
				else if (x1 <= X1  && X2 <= x1  && x2 <= X1  && X2 <= x2 )
				{
					printf("All in\n");
				}
				else
				{
					printf("Part in\n");
				}
			}
		}
	}
	return 0;
}