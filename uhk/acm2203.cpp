#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int Mainl, Assl;
int Next[100010];
char ar[200020], sa[100010], t[100010];
void Cal_Next();
bool KMP();
int main()
{
	int i, j, k;
	while (scanf("%s%s", t + 1, sa + 1) != EOF)
	{
		Mainl = strlen(t + 1);
		Assl = strlen(sa + 1);
		strcpy(ar + 1, t + 1);
		strcat(ar + Mainl + 1, t + 1);
		Mainl = strlen(ar + 1);
		Cal_Next();
		if (KMP())
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
void Cal_Next()
{
	int i, j, L;
	Next[1] = 0;
	for (i = 2; i <= Assl; i++)
	{
		j = Next[i - 1];
		while (sa[j + 1] != sa[i] && j > 0)
			j = Next[j];
		if (sa[j + 1] == sa[i])
			Next[i] = j + 1;
		else
			Next[i] = 0;
	}
}
bool KMP()
{
	int i = 1, j = 1, k, L;
	while (i <= Mainl && j <= Assl)
	{
		if (ar[i] == sa[j])
		{
			if (j == Assl)
				return true;
			i++;
			j++;
		}
		else
		{
			if (j == 1)
				i++;
			else
				j = Next[j - 1] + 1;
		}
	}
	return false;
}
