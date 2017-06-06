#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;
const int MAX = 100000000;
struct node
{
	double ar[205][205];
};
struct node temp, res, start;
void multiply(node &a, node &b, int c);
int main()
{
	int i, j, k, u, n, m, sa[205], a, b, x, y, s;
	double p, t, ans;
	while (scanf("%d %d", &n, &m) != EOF && (n || m))
	{
		memset(start.ar, 0.0, sizeof(start.ar));
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &sa[i]);
		}
		scanf("%d", &k);
		for (i = 1; i <= k; i++)
		{
			scanf("%d %d %lf", &x, &y, &p);
			start.ar[x+1][y+1] += p;
		}
		t = 0.0;
		for (i = 1; i <= n; i++)
		{
			t = 0.0;
			for (j = 1; j <= n; j++)
			{
				t += start.ar[i][j];
			}
			start.ar[i][i] = 1.0 - t;
		}
		memset(res.ar, 0.0, sizeof(res.ar));
		for (i = 1; i <= n; i++)
		{
			res.ar[i][i] = 1.0;
		}
		while (m)
		{
			if (m % 2)
			{
				multiply(res, start, n);
			}
			multiply(start, start, n);
			m /= 2;
		}
		ans = 0.0;
		for (i = 1; i <= n; i++)
		{
			ans += sa[i] * res.ar[i][n];
		}
		printf("%.0lf\n", ans);
	}
	return 0;
}
void multiply(node &a, node &b, int c)
{
	int i, j, k;
	memset(temp.ar, 0, sizeof(temp.ar));
	for (i = 1; i <= c; i++)
	{
		for (j = 1; j <= c; j++)
		{
			for (k = 1; k <= c; k++)
			{
				temp.ar[i][j] += a.ar[i][k] * b.ar[k][j];
			}
		}
	}
	a = temp;
}