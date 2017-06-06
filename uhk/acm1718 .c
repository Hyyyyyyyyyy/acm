#include <stdio.h>
#include <stdlib.h>
int comp(const void *, const void *);
struct student
{
	int grade;
	int id;
};
int main()
{
	int n, m, i, u;
	struct student dodo[1005];
	while (scanf("%d", &n) != EOF)
	{
		i = 0;
		while (scanf("%d %d", &dodo[i].id, &dodo[i].grade) == 2)
		{
			if (dodo[i].grade == 0)
				break;
			i++;
		}
		qsort(dodo, i + 1, sizeof(struct student), comp);
		for (u = 0; u <= i; u++)
			if (n == dodo[u].id)
				break;
		printf("%d\n", u + 1);
	}
	return 0;
}

int comp(const void *a, const void *b)
{
	const struct student * p1 = (const struct student *)a;
	const struct student * p2 = (const struct student *)b;
	if (p1->grade < p1->grade)
		return -1;
	else if (p1->grade == p2->grade)
		return 0;
	else
		return 1;
}
