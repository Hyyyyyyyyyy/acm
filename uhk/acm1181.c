#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
struct node
{
	char begin;
	char end;
	char word;
};
struct node ar[10000];
bool visit[10000];
int k;

bool dfs(char ch);
int main()
{
	int i, j, u, n, m;
	char sa[100];
    bool doudou;
	while (scanf("%s", sa) != EOF)
	{
		k = 1;
		while (strcmp(sa, "0") != 0)
		{
			ar[k].begin = sa[0];
			ar[k].end = sa[strlen(sa) - 1];
			k++;
			scanf("%s", sa);
		}
		doudou = false;
		for (i = 1; i < k; i++)
		{
			if (ar[i].begin == 'b')
			{
				memset(visit, false, sizeof(visit));
				visit[i] = true;
				if (dfs(ar[i].end) == true)
				{
					doudou = true;
					break;
				}
			}
		}
		if (doudou)
			printf("Yes.\n");
		else
			printf("No.\n");
	}
	return 0;
}
bool dfs(char ch)
{
	int i, j;
	if (ch == 'm')
		return true;
	for (i = 1; i < k; i++)
	{
		if (ar[i].begin == ch && !visit[i])
		{
			visit[i] = true;
			if (dfs(ar[i].end) == true)
			{
				return true;
			}
			visit[i] = false;
		}
	}
	return false;
}
