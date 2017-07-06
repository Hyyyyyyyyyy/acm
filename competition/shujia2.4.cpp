#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <cctype>
using namespace std;
const int maxn = 10000;
char S1[] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P' }; //10
char S2[] = { 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L' };//9
char S3[] = { 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };//7
int main()
{
	int i, j, k, n, m, a, b;
	char s1[10], s2[10];
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			int doudou = 0;
			scanf("%s %s", s1, s2);
			if (strcmp(s2, "Right") == 0)
			{
				for (i = 0; i < 10; i++)
				{
					if (s1[0] == S1[i] && i < 9)
					{
						printf("%c\n", S1[i + 1]);
						doudou = 1;
						break;
					}
				}
				for (i = 0; i < 9; i++)
				{
					if (S2[i] == s1[0] && i < 8)
					{
						printf("%c\n", S2[i + 1]);
						doudou = 1;
						break;
					}
				}
				for (i = 0; i < 7; i++)
				{
					if (S3[i] == s1[0] && i < 6)
					{
						printf("%c\n", S3[i + 1]);
						doudou = 1;
						break;
					}
				}
				if(!doudou)
					printf("No letter.\n");
			}
			else
			{
				for (i = 0; i < 10; i++)
				{
					if (s1[0] == S1[i] && i > 0)
					{
						printf("%c\n", S1[i - 1]);
						doudou = 1;
						break;
					}
				}
				for (i = 0; i < 9; i++)
				{
					if (S2[i] == s1[0] && i > 0)
					{
						printf("%c\n", S2[i - 1]);
						doudou = 1;
						break;
					}
				}
				for (i = 0; i < 7; i++)
				{
					if (S3[i] == s1[0] && i > 0)
					{
						printf("%c\n", S3[i - 1]);
						doudou = 1;
						break;
					}
				}
				if(!doudou)
					printf("No letter.\n");
			}
		}
	}
	return 0;
}