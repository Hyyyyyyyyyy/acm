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
const int maxn = 100 + 100;
const int maxm = 1000000 + 100;
map<string, string> mp;
map<string, string>::iterator it;
map<string, int> mmp;
string A;
string B;
string solve()
{
	int i, j;
	if (B[0] == '-')
	{
		return B;
	}
	else if (isdigit(B[0]))
	{
		return B;
	}
	else
	{
		return mp[B];
	}
	return B;
}
int main()
{
	int i, j, k, cas, CAS, N;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d", &N);
			int res = 0;
			mp.clear();
			mmp.clear();
			for (i = 1; i <= N; i++)
			{
				cin >> A >> B;
				mp[A] = solve();
			}
			for (it = mp.begin(); it != mp.end(); it++)
			{
				mmp[it->second] = 1;
			}
			printf("%d\n", mmp.size());
		}
	}
	return 0;
}