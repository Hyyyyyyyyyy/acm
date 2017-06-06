#include <stdio.h>
#include <cstring>
#include <map>
using namespace std;
int Mainl, Assl;
char ar[100010], sa[100010], s[100010];
int Next[100010], EX[100010];
void Cal_Next();
void EKMP();
map<char, char>q;
int main()
{
	int i, j, k, n, m;
	char ch;
	while (scanf("%d", &n)  != EOF)
	{
		getchar();
		q.clear();
		for (m = 1; m <= n; m++)
		{
			scanf("%s", ar);
			for (i = 0; i < 26; i++)
			{
				q[ar[i]] = 'a'+i;
			}
			scanf("%s", sa);
			Mainl = strlen(sa);
			strcpy(s, sa);
			for (i = 0; i < Mainl; i++)
			{
				sa[i] = q[sa[i]];
			}
			EKMP();
			//for (i = 0; i < Mainl; i++)
			//{
			//	printf("%d ", EX[i]);
			//}
			//for (i = 0; i < Mainl; i++)
			//{
			//	printf("%d ", Next[i]);
			//}
			for (i = 0; i < Mainl; i++)
			{
				if (i >= EX[i] && i + EX[i] == Mainl)
					break;
			}
			//puts(sa);
			//puts(s);
			for (j = 0; j < i; j++)
				putchar(s[j]);
			for (j = 0; j < i; j++)
				putchar(sa[j]);
			putchar('\n');
		}
	}
	return 0;
}
void EKMP()
{
	int i = 0, j = 0, k, po = 0;
	Cal_Next();
	while (s[i] == sa[i] && i < Mainl)
		i++;
	EX[0] = i;
	for (i = 1; i < Mainl; i++)
	{
		if (Next[i - po] + i < EX[po] + po)
			EX[i] = Next[i - po];
		else
		{
			j = EX[po] + po - i;
			if (j < 0)
				j = 0;
			while (s[i + j] == sa[j] && i + j < Mainl)
				j++;
			EX[i] = j;
			po = i;
		}
	}
}
void Cal_Next()
{
	int i, j = 0, po = 1;
	Next[0] = Mainl - 1;
	while (sa[j] == sa[j + 1] && j < Mainl)
		j++;
	Next[1] = j;
	for (i = 2; i < Mainl; i++)
	{
		if (Next[i - po] + i < Next[po] + po)
			Next[i] = Next[i - po];
		else
		{
			j = Next[po] + po - i;
			if (j < 0)
				j = 0;
			while (sa[i + j] == sa[j] && i + j < Mainl)
				j++;
			Next[i] = j;
			po = i;
		}
	}
}
