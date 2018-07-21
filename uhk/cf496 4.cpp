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
char S[maxn];
int dp[maxn];
int fin[3];
int sum[maxn];
//dp方法
//sum[i]表示前i个数字和模3是多少
//fin[r]记录的是余数r的最长前缀长度
//dp[i]表示前i个数字能被3整除的有几个
//如果fin[sum[i]] != -1，那么前fin[sum[i]]个数字和前i个数字同余，那么就表示从fin[sum[i]]+1~i个数字和模3为0
//即找到了最短的后缀模3为0，这一定比后缀长的解优
int main()
{
	int i, j, k;
	while (scanf("%s", S + 1) != EOF)
	{
		int L = strlen(S + 1);
		memset(dp, 0, sizeof(dp));
		fin[0] = fin[1] = fin[2] = -1;
		dp[0] = 0;
		sum[0] = 0;
		for (i = 1; i <= L; i++)
		{
			sum[i] = (sum[i - 1] + S[i] - '0') % 3;
		}
		for (i = 1; i <= L; i++)
		{
			if (fin[sum[i]] != -1)
				dp[i] = max(dp[i - 1], dp[fin[sum[i]]] + 1);
			else
				dp[i] = max(dp[i - 1], sum[i] % 3 == 0 ? 1 : 0);
			fin[sum[i]] = i;
		}
		printf("%d\n", dp[L]);
	}
	return 0;
}

//贪心方法
//如果某一个数字能够被3整除则直接分开
//若两个数字能被3整除则分开
//对于任意3个数字，前两个数字没有被3整除，则余数一定为1，1或2，2；那么对于第三个数字不管余数为1还是2，都可以挑出后3个或者后2个数字组成被3整除的数
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
char S[maxn];
int main()
{
	int i, j, k, cnt, sum;
	while (scanf("%s", S) != EOF)
	{
		int L = strlen(S);
		cnt = 0;
		sum = 0;
		int res = 0;
		for (i = 0; i < L; i++)
		{
			cnt++;
			sum = (sum + S[i] - '0') % 3;
			if (cnt == 3 || (S[i] - '0') % 3 == 0 || sum % 3 == 0)
			{
				res++;
				cnt = sum = 0;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}