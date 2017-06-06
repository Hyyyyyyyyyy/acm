#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 100000000;
int ar[50010*4];
int sa[50010*4];
void build(int root, int begin, int end);
void update(int root, int begin, int end, int index, int val);
int query(int root, int begin, int end, int b, int e);
int main()
{
	int i, j, k, u, n, m, a, b, c, d, doudou;
	char s[10];
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			doudou = 0;
			memset(ar, 0, sizeof(ar));
			scanf("%d", &k);
			for (u = 1; u <= k; u++)
			{
				scanf("%d", &ar[u]);
			}
			memset(sa, 0, sizeof(sa));
			build(1, 1, k);
			scanf("%s", s);
			while (strcmp(s, "End"))
			{
				if (strcmp(s, "Add") == 0)
				{
					scanf("%d %d", &a, &b);
					update(1, 1, k, a, b);
				}
				else if (strcmp(s, "Sub") == 0)
				{
					scanf("%d %d", &a, &b);
					update(1, 1, k, a, -b);
				}
				else
				{
					scanf("%d %d", &a, &b);
					if (doudou == 0)
						printf("Case %d:\n", m);
					doudou = 1;
					printf("%d\n", query(1, 1, k, a, b));
				}
				scanf("%s", s);
			}
		}
	}
	return 0;
}
void build(int root, int begin, int end)
{
	if (begin == end)
		sa[root] = ar[begin];
	else
	{
		build(root * 2, begin, (begin + end) / 2);
		build(root * 2 + 1, (begin + end) / 2 + 1, end);
		sa[root] = sa[root * 2] + sa[root * 2 + 1];
	}
}
void update(int root, int begin, int end, int index, int val)
{
	if (begin == end)
	{
			sa[root] += val;
		return;
	}
	int mid = (begin + end) / 2;
	if (index <= mid)
		update(root * 2, begin, mid, index, val);
	else
		update(root * 2 + 1, mid + 1, end, index, val);
	sa[root] = sa[root * 2] + sa[root * 2 + 1];
}
int query(int root, int begin, int end, int b, int e)
{
    if(begin >= b && end <= e)
        return sa[root];
    if(begin > e || end < b)
        return 0;
    return query(root*2, begin, (begin + end)/2, b, e) + query(root*2+1, (begin + end)/2+1, end, b, e);
}
