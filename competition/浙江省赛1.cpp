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
const ll inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1e7 + 7;
const ll maxn = 10000 + 100;
const ll maxm = 1000000 + 100;
int N, B;
int ar[maxn];
int main()
{
	int i, j, CAS, cas;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d %d", &N, &B);
			int doudou = 0;
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &j);
				if ((j + B) % 7 == 0)
				{
					doudou = 1;
				}
			}
			if (doudou)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}