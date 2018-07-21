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
const int maxn = 300000 + 100;
const int maxm = 1000000 + 100;
map<int, int>mp;
int ar[maxn];
int N;
int main()
{
	int i, j, k, Max;
	while (scanf("%d", &N) != EOF)
	{
		mp.clear();
		Max = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
			if (mp.find(ar[i]) == mp.end())
			{
				mp[ar[i]] = 1;
			}
			else
				mp[ar[i]]++;
			Max = max(Max, mp[ar[i]]);
		}
		printf("%d\n", N-Max);
	}
	return 0;
}

//这个换顺序是可以随意换的
//则可以sort从小到大，然后左移，那么最好的情况是把出现次数最多的数字全部都移开了
//也有可能总个数比较少，不能完全移开，那么最多也只有N-Max个不同数字