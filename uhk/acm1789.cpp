#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
const int MAX = 100000000;
using namespace std;
struct point
{
	int data;
	int score;
};
bool comp(const point a, const point b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else
		return a.data < b.data;
}
int main()
{
	int i, j, k, u, n, m, set[100010], sum, doudou;
	struct point ar[100010], temp;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &k);
			for (i = 1; i <= k; i++)
			{
				scanf("%d", &ar[i].data);
			}
			for (i = 1; i <= k; i++)
			{
				scanf("%d", &ar[i].score);
			}
			sort(ar + 1, ar + 1 + k, comp);
			sum = 0;
			memset(set, 0, sizeof(set));
			doudou = 0;
			for (i = 1; i <= k; i++)
			{
				if (set[ar[i].data])
				{
					for (j = ar[i].data; j >= 1; j--)
					{
						if (!set[j])
						{
							set[j] = i;
							break;
						}
					}
					if (!j)
					{
						sum += ar[i].score;
					}
				}
				else
				{
					set[ar[i].data] = i;
				}
			}
			printf("%d\n", sum);
		}
	}
	return 0;
}