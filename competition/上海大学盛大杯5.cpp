#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cctype>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 110;
typedef long long ll;
char s[maxn];
int ar[maxn];
map<char, int>q;
ll N;
int main()
{
	int i, j, k, u, n, m;
	q['a'] = 0;
	q['b'] = 1;
	q['c'] = 2;
	q['d'] = 3;
	q['e'] = 4;
	q['f'] = 5;
	q['g'] = 6;
	q['h'] = 7;
	q['i'] = 8;
	q['j'] = 9;
	q['k'] = 10;
	q['l'] = 11;
	q['m'] = 12;
	q['n'] = 13;
	q['o'] = 14;
	q['p'] = 15;
	q['q'] = 16;
	q['r'] = 17;
	q['s'] = 18;
	q['t'] = 19;
	q['u'] = 20;
	q['v'] = 21;
	q['w'] = 22;
	q['x'] = 23;
	q['y'] = 24;
	q['z'] = 25;
	while (scanf("%s %lld", s, &N) != EOF)
	{
		memset(ar, 0, sizeof(ar));
		ll RES = 0;
		int L = strlen(s);
		for (i = 0; i < L; i++)
		{
			RES += q[s[i]] * (ll)pow(26, L - i - 1);
		}
		i = 1;
		while (RES)
		{
			ar[i++] = RES % N;
			RES /= N;
		}
		if (i > 1)
		{
			for (j = i - 1; j >= 1; j--)
				printf("%d", ar[j]);
		}
		else
			printf("0");
		putchar('\n');
	}
	return 0;
}