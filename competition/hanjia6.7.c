#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
struct acm
{
	int time;
	char sta[20];
	char id;
};
int main()
{
	int i, j, k, u, n, m, set[26];
	struct acm ar[101];
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &k);
			memset(set, 0, sizeof(set));
			for (u = 1; u <= k; u++)
			{
				scanf("%d %c %s", &ar[u].time, &ar[u].id, ar[u].sta);
				if (strcmp(ar[u].sta, "Accept") == 0)
				{
					set[ar[u].id - 'A'] = 1;
				}
				if (strcmp(ar[u].sta, "Wrong") == 0 && set[ar[u].id - 'A'] == 0)
				{
					set[ar[u].id - 'A'] = -1;
				}
			}
			printf("Accept: ");
			for (i = 0; i < 26; i++)
				if (set[i] == 1)
					printf("%c", i + 'A');
			putchar('\n');
			printf("Wrong: ");
			for (i = 0; i < 26; i++)
				if (set[i] == -1)
					printf("%c", i + 'A');
			putchar('\n');
			putchar('\n');
		}
	}
	return 0;
}