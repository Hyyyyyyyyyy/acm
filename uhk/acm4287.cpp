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
const int inf = 1000000000;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 5000 + 100;
const int maxm = 5000 + 100;
map<char, int> mp;
map<int, int> mpp;
int ar[maxn];
char s[10];
int dic[maxn];
int N, M;
int main()
{
	mp.clear();
	mp['a'] = mp['b'] = mp['c'] = 2;
	mp['d'] = mp['e'] = mp['f'] = 3;
	mp['g'] = mp['h'] = mp['i'] = 4;
	mp['j'] = mp['k'] = mp['l'] = 5;
	mp['m'] = mp['n'] = mp['o'] = 6;
	mp['p'] = mp['q'] = mp['r'] = mp['s'] = 7;
	mp['t'] = mp['u'] = mp['v'] = 8;
	mp['w'] = mp['x'] = mp['y'] = mp['z'] = 9;
	int i, j, k, cas, CAS, a, b;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			memset(dic, 0, sizeof(dic));
			scanf("%d %d", &N, &M);
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i]);
			}
			mpp.clear();
			int cnt = 0;
			for (i = 1; i <= M; i++)
			{
				scanf("%s", s);
				int L = strlen(s);
				b = 0;
				for (j = 0; j < L; j++)
				{
					b = b * 10 + mp[s[j]];
				}
				if (mpp.find(b) == mpp.end())
				{
					mpp[b] = cnt++;
				}
				dic[mpp[b]]++;
			}
			for (i = 1; i <= N; i++)
			{
				if (mpp.find(ar[i]) == mpp.end())
					printf("0\n");
				else
					printf("%d\n", dic[mpp[ar[i]]]);
			}
		}
	}
	return 0;
}