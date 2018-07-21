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
char s[maxn];
int main()
{
	int i, j, k;
	while (scanf("%d", &N) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%s", s);
			int L = strlen(s);
			int doudou = 1;
			if (L != 10)
				doudou = 0;
			for (j = 0; j < L; j++)
			{
				if (j == 0)
				{
					if (s[j] != 'L')
						doudou = 0;
				}
				else if (j == 1)
				{
					if (s[j] != 'Q')
						doudou = 0;
				}
				else
				{
					if (!isdigit(s[j]))
					{
						doudou = 0;
					}
				}
			}
			if (doudou)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}