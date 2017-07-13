#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <cctype>
using namespace std;
const int maxn = 1000;
const int INF = 1e9;
typedef long long ll;
char s[maxn];
char CC[maxn], DD[maxn], EE[maxn], FF[maxn];
char now[maxn];
int main()
{
	int i, j, k, u, n, m;
	char ch = '\\';
	while (scanf("%d", &n) != EOF)
	{
		strcpy(now, "C:\\users\\godle\0");
		strcpy(CC, "C:\\users\\godle\0");
		strcpy(DD, "D:\0");
		strcpy(EE, "E:\0");
		strcpy(FF, "F:\0");
		for (m = 1; m <= n; m++)
		{
			scanf("%s", s);
			if (strcmp(s, "cd") == 0)
			{
				scanf("%s", s);
				if (strcmp(s, "..") == 0)
				{
					int L = strlen(now);
					for (i = L - 1; i >= 0; i--)
					{
						if (now[i] == ch)
						{
							now[i] = 0;
							break;
						}
					}
					if (now[0] == 'C')
					{
						strcpy(CC, now);
					}
					else if (now[0] == 'D')
					{
						strcpy(DD, now);
					}
					else if (now[0] == 'E')
					{
						strcpy(EE, now);
					}
					else if(now[0] == 'F')
					{
						strcpy(FF, now);
					}
				}
				else
				{
					int L = strlen(now);
					int l = strlen(s);
					strcat(now, "\\");
					strcat(now, s);
					if (now[0] == 'C')
					{
						strcpy(CC, now);
					}
					else if (now[0] == 'D')
					{
						strcpy(DD, now);
					}
					else if (now[0] == 'E')
					{
						strcpy(EE, now);
					}
					else
					{
						strcpy(FF, now);
					}
				}
				printf("%s", now);
				putchar('\n');
			}
			else if (strcmp(s, "C:") == 0)
			{
				printf("%s", CC);
				putchar('\n');
				strcpy(now, CC);
			}
			else if (strcmp(s, "D:") == 0)
			{
				printf("%s", DD);
				putchar('\n');
				strcpy(now, DD);
			}
			else if (strcmp(s, "E:") == 0)
			{
				printf("%s", EE);
				putchar('\n');
				strcpy(now, EE);
			}
			else if (strcmp(s, "F:") == 0)
			{
				printf("%s", FF);
				putchar('\n');
				strcpy(now, FF);
			}
		}
	}
	return 0;
}