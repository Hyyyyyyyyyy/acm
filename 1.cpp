#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
using namespace std;
const int maxn = 1000000 + 10;
typedef long long ll;
int ar[maxn];
int main()
{
	int i, j, k, u, n, m;
	int cnt = 0;
	for (i = 1; i <= 1000000; i++)
	{
		if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0)
		{
			cnt++;
		}
		ar[i] = cnt;
	}
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &k);
			printf("%d\n", ar[k]);
		}
	}
	return 0;
}