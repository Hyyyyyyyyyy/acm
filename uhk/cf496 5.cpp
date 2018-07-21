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
int ar[maxn];
int great[maxn * 2];
int N, M;
int main()
{
	int i, j, k;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
		}
		ll res = 0;
		int sum = 0;
		bool doudou = 0;
		memset(great, 0, sizeof(great));
		great[N] = 1;
		for (i = 1; i <= N; i++)
		{
			if (ar[i] > M)
				sum++;
			else if (ar[i] < M)
				sum--;
			if (ar[i] == M)
				doudou = 1;
			if (doudou)
				res += great[sum + N] + great[sum - 1 + N];
			else
				great[sum + N]++;
		}
		printf("%lld\n", res);
	}
	return 0;
}
//great[i]表示位置在M之前的比M大的数有几个。那么遍历记录当前位置的前缀里有多少个数比M大，若当前位置在M之前则记录
//因为有负数，所以把-N~N映射到0~2*N
//若在M之后，就表明当前位置前缀里比M大的个数与M之前某些位置比M大的个数相等，那么中间的数，M就是中位数。
//根据它对中位数的定义，比M大的个数如果比M小的个数少1 也是可以的
//注意最开始和M相等的位置一定有一个，great[0+N] = 1;