#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 100000000;
struct node
{
	double x;
	double y;
	double s;
};
bool comp(node a, node b)
{
	return a.s < b.s;
}
int main()
{
	int i, j, k, u, n, m, cnt;
	struct node ar[100010];
	double sa[1000010], a, b, c, min;
	while (scanf("%d", &n) != EOF && n)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lf %lf", &ar[m].x, &ar[m].y);
			ar[m].s = ar[m].x + ar[m].y;
		}
		sort(ar + 1, ar + 1 + n, comp);
		cnt = 1;
		min = MAX;
		for (i = 1; i <= n; i++)
		{
			for (j = i + 1; j <= i + 1 + 6 && j <= n; j++)
			{
				sa[cnt] = sqrt((ar[i].x - ar[j].x)*(ar[i].x - ar[j].x) + (ar[i].y - ar[j].y)*(ar[i].y - ar[j].y));
				if (min > sa[cnt])
					min = sa[cnt];
				cnt++;
			}
		}
		printf("%.2lf\n", min / 2.0);
	}
	return 0;
}