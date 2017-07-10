#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cctype>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 100000 + 100;
typedef long long ll;
char s[maxn];
int I, l, o, v, c, S, e;
int main()
{
	int i, j, n, m;
	while (scanf("%s", s) != EOF)
	{
		int L = strlen(s);
		I = l = o = v = c = S = e = 0;
		for (i = 0; i < L; i++)
		{
			if (s[i] == 'I' || s[i] == 'i')
				I++;
			if (s[i] == 'l' || s[i] == 'L')
				l++;
			if (s[i] == 'o' || s[i] == 'O')
				o++;
			if (s[i] == 'v' || s[i] == 'V')
				v++;
			if (s[i] == 'c' || s[i] == 'C')
				c++;
			if (s[i] == 's' || s[i] == 'S')
				S++;
			if (s[i] == 'e' || s[i] == 'E')
				e++;
		}
		e /= 2;
		printf("%d\n", min(I, min(l, min(o, min(v, min(c, min(S, e)))))));
	}
	return 0;
}