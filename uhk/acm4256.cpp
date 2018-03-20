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
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 40000 + 100;
const int maxm = 1000000 + 100;
char S[maxn];
map<string, int> mp;
int main()
{
	int i, j, k, N, cas = 1;
	mp["I"] = 1;
	mp["II"] = 2;
	mp["III"] = 3;
	mp["IV"] = 4;
	mp["V"] = 5;
	mp["VI"] = 6;
	mp["VII"] = 7;
	mp["VIII"] = 8;
	mp["IX"] = 9;
	mp["X"] = 10;
	mp["XI"] = 11;
	mp["XII"] = 12;

	while (scanf("%s", &S) != EOF)
	{
			printf("Case %d: %d\n", cas++, mp[S]);
	}
	return 0;
}
