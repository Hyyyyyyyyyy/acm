#include <stdio.h>
int main()
{
	int p, i, count, ar[9999][3], set[9999], key0, key1, key2, j, S;
	while (scanf("%d", &p) != EOF)
	{
		if (p == 0)
			break;
		for (i = 1; i <= p; i++)
			set[i] = i;
		ar[0][2] = -1;
		for (i = 1; i <= (p*(p - 1) / 2); i++)
		{
			scanf("%d %d %d", &ar[i][0], &ar[i][1], &ar[i][2]);

			key2 = ar[i][2];
			key1 = ar[i][1];
			key0 = ar[i][0];
			j = i - 1;
			while (j > 0 && key2 < ar[j][2])
			{
				ar[j + 1][2] = ar[j][2];
				ar[j + 1][1] = ar[j][1];
				ar[j + 1][0] = ar[j][0];
				j--;
			}
			ar[j + 1][2] = key2;
			ar[j + 1][1] = key1;
			ar[j + 1][0] = key0;
		}
		S = 0;
		for (i = 1, count = 0; count < p - 1; i++)
		{
			while (set[ar[i][0]] != ar[i][0])
				ar[i][0] = set[ar[i][0]];
			while (set[ar[i][1]] != ar[i][1])
				ar[i][1] = set[ar[i][1]];
			if (set[ar[i][0]] != set[ar[i][1]])
			{
				set[ar[i][1]] = ar[i][0];
				count++;
				S += ar[i][2];
			}
		}

		printf("%d\n", S);
	}
	return 0;
}
