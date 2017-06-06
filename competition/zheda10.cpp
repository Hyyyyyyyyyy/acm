#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int Mainl, Assl;
void Cal_Next();
int KMP();
int Next[10];
char ar[1010], sa[10];
int main()
{
	int i, j, k, u, n, m, a, b, sum;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%s", ar + 1);
			Mainl = strlen(ar + 1);
			sum = 0;
			sa[1] = 'd';
			sa[2] = 'o';
			sa[3] = 'g';
			sa[4] = '\0';
			Assl = strlen(sa + 1);
			Cal_Next();
			sum += KMP();
			sa[1] = 'c';
			sa[2] = 'a';
			sa[3] = 't';
			sa[4] = '\0';
			sum += KMP();
			printf("%d\n", sum);
		}
	}
}
int KMP()
{
	int i, j, L1, L2, doudou = 0, s = 0;
	i = 1;
	j = 1;
	while (i <= Mainl)
	{
		if (ar[i] == sa[j])
		{
			if (j == Assl)
			{
				s++;
				j = 1;
				i++;
			}
			else;
			i++;
			j++;
		}
		else
		{
			if (j == 1)
			{
				i++;
			}
			else
			{
				j = Next[j - 1] + 1;
			}
		}
	}
	return s;
}
void Cal_Next()
{
	int i, j, k, L1, L2;
	Next[1] = 0;
	for (i = 2; i <= Assl; i++)
	{
		j = Next[i - 1];
		while (sa[i] != sa[j + 1] && j > 0)
		{
			j = Next[j];
		}
		if (sa[i] == sa[j + 1])
			Next[i] = j + 1;
		else
			Next[i] = 0;
	}
}
