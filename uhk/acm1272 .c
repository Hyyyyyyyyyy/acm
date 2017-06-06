#include <stdio.h>
int main()
{
	int n, m, set[100005], sut[100005], i, u, a, b, count, doudou, cont;

	for (u = 1; u <= 100004; u++)
		set[u] = u;
	for (u = 1; u <= 100004; u++)
		sut[u] = 0;
	count = 0;
	cont = 0;
	doudou = 1;
	while (scanf("%d %d", &n, &m) != EOF && (n != -1 || m != -1))
	{
		sut[n] = 1;
		sut[m] = 1;
		if (n == 0 && m == 0)
		{
			if (cont == 0)
				printf("Yes\n");
			else
			{
				for (i = 1; i <= 100004; i++)
					if (sut[i] == 1)
						count++;
				if (cont == (count - 1) && doudou == 1)
					printf("Yes\n");
				else
					printf("No\n");
			}
			count = 0;
			cont = 0;
			doudou = 1;
			for (u = 1; u <= 100004; u++)
				set[u] = u;
			for (u = 1; u <= 100004; u++)
				sut[u] = 0;
			continue;
		}

		a = n;
		b = m;
		while (set[a] != a)
			a = set[a];
		while (set[b] != b)
			b = set[b];
		if (a != b)
		{
			set[b] = a;
			cont++;
		}
		else
			doudou = 0;
	}
	getchar();
	return 0;
}
