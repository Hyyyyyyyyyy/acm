#include <cstdio>
#include <cstring>
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
#define foR for
#define for9 for
typedef long long ll;
typedef unsigned long long ull;
const int inf = (1ll << 31) - 1;
const ll INF = (1ull << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1e9;
const int maxn = 50000 + 100;
const int maxm = 1000000 + 100;
char s[maxn];
char ar[maxn];
char stacks[10];
char* change1(char ch)
{
	int n = (int)ch;
	int top = 0;
	while (n)
	{
		if (n % 16 < 10)
		{
			stacks[top++] = '0' + n % 16;
		}
		else
		{
			stacks[top++] = 'a' + n % 16 - 10;
		}
		n /= 16;
	}
	stacks[top] = 0;
	reverse(stacks, stacks + top);
	return stacks;
}
char* change2(int n)
{
	int top = 1;
	memset(stacks, '0', sizeof(stacks));
	while (n)
	{
		if (n % 16 < 10)
		{
			stacks[top++] = '0' + n % 16;
		}
		else
		{
			stacks[top++] = 'a' + n % 16 - 10;
		}
		n /= 16;
	}
	stacks[4] = 0;
	reverse(stacks, stacks + 4);
	return stacks;
}
int main()
{
	int i, j, k, Row;
	while (fgets(s, maxn - 1, stdin) != NULL)
	{
		int L = strlen(s) - 1;
		Row = 0;
		for (i = 1; i * 16 <= L; i++)
		{
			strncpy(ar, s + (i - 1) * 16, 16);
			ar[16] = 0;
			printf("%s:", change2(i - 1));
			for (j = 0; j < 16; j++)
			{
				if (j % 2 == 0)
				{
					printf(" ");
				}
				printf("%s", change1(ar[j]));
				if (isupper(ar[j]))
					ar[j] = tolower(ar[j]);
				else
					ar[j] = toupper(ar[j]);
			}
			putchar(' ');
			fputs(ar, stdout);
			putchar('\n');
		}
		if ((i - 1) * 16 != L)
		{
			printf("%s:", change2(i - 1));
			int Len = L - (i - 1) * 16;
			strncpy(ar, s + (i - 1) * 16, Len);
			ar[Len] = 0;
			for (j = 0; j < Len; j++)
			{
				if (j % 2 == 0)
				{
					printf(" ");
				}
				printf("%s", change1(ar[j]));
				if (isupper(ar[j]))
					ar[j] = tolower(ar[j]);
				else
					ar[j] = toupper(ar[j]);
			}
			for (; j < 16; j++)
			{
				if (j % 2 == 0)
					putchar(' ');
				printf("  ");
			}
			putchar(' ');
			fputs(ar, stdout);
			putchar('\n');
		}

	}
	return 0;
}