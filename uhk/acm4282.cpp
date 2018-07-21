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
ll POW[50100][50];
bool Binary_Search(ll x, ll z, ll K)
{
	ll L = x+1;
	ll R = 50000;
	ll mid;
	while (L <= R)
	{
		mid = (L + R) / 2;
		if (POW[mid][z] == 0)
		{
			R = mid - 1;
			continue;
		}
		if (POW[mid][z] + x * mid*z < K - POW[x][z])
			L = mid + 1;
		else if (POW[mid][z] + x * mid*z > K - POW[x][z])
			R = mid - 1;
		else
			return true;
	}
		return false;
}
int main()
{
	ll i, j, k, K;
	for (i = 1; i <= 50000; i++)
	{
		POW[i][0] = 1;
		POW[i][1] = i;
		for (j = 2; j <= 40; j++)
		{
			POW[i][j] = POW[i][j - 1] * i;
			if (POW[i][j] > inf)
				break;
		}
	}
	while (scanf("%lld", &K) != EOF && K)
	{
		ll res = 0;
		for (i = 1; i <= 50000; i++)
		{
			for (j = 2; j <= 31; j++)
			{
				if (K - POW[i][j] <= 0)
					break;
				if (POW[i][j] == 0)
					break;
				if (Binary_Search(i, j, K))
					res++;
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}