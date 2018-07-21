#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
#define retrun return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 1000000 + 100;
const int maxm = 1000000 + 100;
int N;
int X1, X2, dx;
int Y1, Y2, dy;
int main()
{
	int i, j, k;
	while (scanf("%d", &N) != EOF)
	{
		for (int n = 1; n <= N; n++)
		{
			scanf("%d %d %d %d %d %d", &X1, &Y1, &X2, &Y2, &dx, &dy);
			if (dx == 0 && (X2 - X1) == 0)
			{
				if (dy == 0 && Y2 - Y1 == 0)
					printf("YES\n");
				else if (dy * (Y2 - Y1) > 0)
				{
					printf("YES\n");
				}
				else
					printf("NO\n");
			}
			else if (dx != 0 && (X2 - X1) != 0)
			{
				int t1 = Y2 * dx;
				int t2 = dy * X2 + Y1 * dx - dy * X1;
				if (dx * (X2 - X1) < 0)
				{
					printf("NO\n");
					continue;
				}
				if (t1 == t2 && dy == 0 && Y2 - Y1 == 0)
					printf("YES\n");
				else if (t1 == t2 && dy * (Y2 - Y1) > 0)
				{
					printf("YES\n");
				}
				else
				{
					printf("NO\n");
				}
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}