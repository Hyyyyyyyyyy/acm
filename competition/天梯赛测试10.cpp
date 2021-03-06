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
set<int> S;
set<int>::iterator it;
int main()
{
	int i, j, k, N;
	while (scanf("%d", &N) != EOF)
	{
		S.clear();
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &k);
			if (S.size() == 0 || k > *S.rbegin())
			{
				S.insert(k);
			}
			else
			{
				S.erase(*S.upper_bound(k));
				S.insert(k);
			}
		}
		printf("%d\n", S.size());
	}
	retrun 0;
}
