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
const ll MOD = 100000007ll;
const int maxn = 50000 + 100;
const int maxm = 100000 + 100;
// map<int, char> mp;
char s[maxn];
// char change(int x)
// {
// 	int i, j, res;
// 	res = 0;
// 	i = 0;
// 	while (x)
// 	{
// 		if (x & 1)
// 		{
// 			res += (1 << i);
// 		}
// 		x /= 10;
// 		i++;
// 	}
// 	return mp[res];
// }
int main()
{
	int i, j, L;
	// mp[0] = 'A';
	// mp[1] = 'B';
	// mp[2] = 'C';
	// mp[3] = 'D';
	// mp[4] = 'E';
	// mp[5] = 'F';
	// mp[6] = 'G';
	// mp[7] = 'H';
	// mp[8] = 'I';
	// mp[9] = 'J';
	// mp[10] = 'K';
	// mp[11] = 'L';
	// mp[12] = 'M';
	// mp[13] = 'N';
	// mp[14] = 'O';
	// mp[15] = 'P';
	// mp[16] = 'Q';
	// mp[17] = 'R';
	// mp[18] = 'S';
	// mp[19] = 'T';
	// mp[20] = 'U';
	// mp[21] = 'V';
	// mp[22] = 'W';
	// mp[23] = 'X';
	// mp[24] = 'Y';
	// mp[25] = 'Z';
	while (scanf("%d", &L) != EOF)
	{
		scanf("%s", s);
		for (i = 0; i < L; i += 5)
		{
			int t = 0;
			for (j = 0; j < 5; j++)
			{
				if (isdigit(s[i + j]))
				{
					t += (1 << (4 - j));
				}
			}
			printf("%c", t + 65);
		}
		putchar('\n');
	}
	return 0;
}