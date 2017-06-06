#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int MAX = 100000000;
struct node
{
	int val;
	double per;
	int num;
};
struct node ar[1010];
bool comp(node a, node b)
{
	return a.per > b.per;
}
int main()
{
	int i, j, k, u, n, m, a, b, c, cost, cnt;
	double bag;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &cost, &cnt);
			for (i = 1; i <= cnt; i++)
			{
				scanf("%d %d", &ar[i].val, &ar[i].num);
				ar[i].per = 1.0 / (double)ar[i].val;
			}
			sort(ar + 1, ar + 1 + cnt, comp);
			bag = 0.0;
			for (i = 1; i <= cnt; i++)
			{
				if (cost >= ar[i].val * ar[i].num)
				{
					cost -= ar[i].val*ar[i].num;
					bag += (double)ar[i].num;
				}
				else
				{
					bag += (double)cost * ar[i].per;
					break;
				}
			}
			printf("%.2lf\n", bag);
		}
	}
	return 0;
}