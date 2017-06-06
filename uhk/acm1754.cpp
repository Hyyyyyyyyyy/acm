#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 100000000;
int max(int a, int b) { return (a > b) ? a : b; }
int ar[200000 * 4];
int sa[200000 * 4];
void build(int root, int begin, int end);
void update(int root, int begin, int end, int index, int val);
int query(int root, int begin, int end, int b, int e);
int main()
{
	int i, j, k, u, n, m, a, b;
	char s[10];
	while (scanf("%d %d", &n, &m) != EOF)
	{
		memset(ar, 0, sizeof(ar));
		for (i = 1; i <= n; i++)
			scanf("%d", &ar[i]);
		build(1, 1, n);
		for (u = 1; u <= m; u++)
		{
			scanf("%s%d%d", s, &a, &b);
			if (strcmp(s, "Q") == 0)
			{
				printf("%d\n", query(1, 1, n, a, b));
			}
			if (strcmp(s, "U") == 0)
			{
				update(1, 1, n, a, b);
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
		sa[root] = max(sa[root * 2], sa[root * 2 + 1]);
	}
}
void update(int root, int begin, int end, int index, int val)
{
	if (begin == end)
		sa[root] = val;
	else
	{
		int mid = (begin + end) / 2;
		if (mid < index)
			update(root * 2 + 1, mid + 1, end, index, val);
		else
			update(root * 2, begin, mid, index, val);
		sa[root] = max(sa[root * 2], sa[root * 2 + 1]);
	}
}
int query(int root, int begin, int end, int b, int e)
{
	int mid = (begin + end) / 2;
	if (begin >= b && end <= e)
		return sa[root];
	if (begin > e || end < b)
		return 0;
	else
		return max(query(root * 2, begin, mid, b, e), query(root * 2 + 1, mid + 1, end, b, e));
}