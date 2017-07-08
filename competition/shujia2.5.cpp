#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;
const int INF = 1000000000;
const int maxn = 50;
char s[maxn], ar[maxn * 3];
char digit[maxn];
char upper[maxn], lower[maxn];
int cnt1, cnt2, cnt3, L;
int dp[maxn][maxn];
int solve()
{
	int i, j, k;
	for (i = 0; i <= L; i++)
	{
		for (j = 0; j <= L; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			if (s[i] != ar[j])
			{
				dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
			}
			if (s[i] == ar[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			//if (MAX < dp[i][j])
			//	MAX = dp[i][j];
		}
	}
	return dp[L][L];
}
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%s", s+1);
			L = strlen(s+1);
			cnt1 = cnt2 = cnt3 = 0;
			for (i = 1; i <= L; i++)
			{
				if (isdigit(s[i]))
				{
					digit[++cnt1] = s[i];
				}
				else if (isupper(s[i]))
				{
					upper[++cnt2] = s[i];
				}
				else
				{
					lower[++cnt3] = s[i];
				}
			}
			int MAX = -INF;
			sort(digit+1, digit + cnt1+1);
			sort(upper+1, upper + cnt2 +1);
			sort(lower+1, lower + cnt3+1);
			if (1)   //digit upper lower
			{
				memset(ar, 0, sizeof(ar));
				strcat(ar+1, digit+1);
				strcat(ar+1, upper+1);
				strcat(ar+1, lower+1);
				int x = solve();
				if (MAX < x)
					MAX = x;
			}
			if (2)   //digit lower upper
			{
				memset(ar, 0, sizeof(ar));
				strcat(ar+1, digit + 1);
				strcat(ar + 1, lower + 1);
				strcat(ar + 1, upper + 1);
				int x = solve();
				if (MAX < x)
					MAX = x;
			}
			if (3)   //upper lower digit
			{
				memset(ar, 0, sizeof(ar));
				strcat(ar + 1, upper + 1);
				strcat(ar + 1, lower + 1);
				strcat(ar + 1, digit + 1);
				int x = solve();
				if (MAX < x)
					MAX = x;
			}
			if (4)   //upper digit lower
			{
				memset(ar, 0, sizeof(ar));
				strcat(ar + 1, upper + 1);
				strcat(ar + 1, digit + 1);
				strcat(ar + 1, lower + 1);
				int x = solve();
				if (MAX < x)
					MAX = x;
			}
			if (5)   //lower digit upper
			{
				memset(ar, 0, sizeof(ar));
				strcat(ar + 1, lower + 1);
				strcat(ar + 1, digit + 1);
				strcat(ar + 1, upper + 1);
				int x = solve();
				if (MAX < x)
					MAX = x;
			}
			if (6)   //lower upper digit
			{
				memset(ar, 0, sizeof(ar));
				strcat(ar + 1, lower + 1);
				strcat(ar + 1, upper + 1);
				strcat(ar + 1, digit + 1);
				int x = solve();
				if (MAX < x)
					MAX = x;
			}
			printf("%d\n", L - MAX);
		}
	}
	return 0;
}