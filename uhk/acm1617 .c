#include <stdio.h>
#include <stdlib.h>

struct phone
{
	int sta;
	struct phone *next[10];
};
int insert(struct phone *root, char *s);
void del(struct phone *root);
int main()
{
	int i, j, k, m, n, u, doudou;
	char ar[10005];
	struct phone *root;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &k);
			root = (struct phone *)malloc(sizeof(struct phone));
			for (i = 0; i < 10; i++)
				root->next[i] = NULL;
			root->sta = 0;
			doudou = 1;
			for (u = 1; u <= k; u++)
			{
				scanf("%s", ar);
				if (doudou == 1 && insert(root, ar))
					doudou = 1;
				else
					doudou = 0;
			}
			if (doudou)
				printf("YES\n");
			else
				printf("NO\n");
			del(root);
		}

	}
	return 0;
}

int insert(struct phone *root, char *s)
{
	struct phone *p = root, *temp;
	int i, doudou = 1;
	while (*s != '\0')
	{
		if (p->next[*s - '0'] == NULL)
		{
			if (p->sta == 1)
				doudou = 0;
			temp = (struct phone *)malloc(sizeof(struct phone));
			for (i = 0; i < 10; i++)
				temp->next[i] = NULL;
			temp->sta = 0;
			p->next[*s - '0'] = temp;

		}
		else
		{
			if (*(s + 1) == '\0')
				doudou = 0;
		}
		p = p->next[*s - '0'];
		s++;
	}
	p->sta = 1;
	return doudou;
}

void del(struct phone *root)
{
	int i;
	for (i = 0; i< 10; i++)
	{
		if (root->next[i] != NULL)
			del(root->next[i]);
	}
	free(root);
}