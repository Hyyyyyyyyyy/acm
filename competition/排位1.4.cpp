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
const int maxn = 10 + 100;
const int maxm = 1000000 + 100;
int ar[maxn][maxn];
int main()
{
	int i, j, k, cas, CAS;
	int x, y, ans;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			for (i = 1; i <= 10; i++)
			{
				for (j = 1; j <= 9; j++)
				{
					scanf("%d", &ar[i][j]);
					if (ar[i][j] == 3)
					{
						x = i;
						y = j;
					}
				}
			}
			scanf("%d", &ans);
			int res = 0;
			for (i = x; i <= 10; i++)
			{
				if (ar[i][y] == 2)
				{
					res++;
					break;
				}
				if (ar[i][y] == 1)
				{
					break;
				}
			}
			for (i = x; i >= 1; i--)
			{
				if (ar[i][y] == 2)
				{
					res++;
					break;
				}
				if (ar[i][y] == 1)
				{
					break;
				}
			}
			for (j = y; j <= 9; j++)
			{
				if (ar[x][j] == 2)
				{
					res++;
					break;
				}
				if (ar[x][j] == 1)
				{
					break;
				}
			}
			for (j = y; j >= 1; j--)
			{
				if (ar[x][j] == 2)
				{
					res++;
					break;
				}
				if (ar[x][j] == 1)
				{
					break;
				}
			}
			if (res == ans)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}