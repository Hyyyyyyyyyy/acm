#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct wocao
{
	int count;
	struct wocao *next[26];
};
void insert(struct wocao *root, char *ar);
int search(struct wocao *root, char *ar);
void del(struct wocao *root);
int main()
{
	char ar[101], a[101], set[20001];
	int i, j, k, u, n, m, count, doudou;
	struct wocao * root;
	while (scanf("%d", &n) != EOF && n)
	{
		scanf("%d", &m);
		root = (struct wocao *)malloc(sizeof(struct wocao));
		for (i = 0; i < 26; i++)
		{
			root->next[i] = NULL;
		}
		root->count = 0;
		for (u = 1; u <= n; u++)
		{
			scanf("%s", ar);
			insert(root, ar);
		}
		count = 0;
		memset(set, 0, sizeof(set));
		for (u = 1; u <= m; u++)
		{
			scanf("%s", a);
			if (search(root, a))
				count++;
		}
		printf("%d\n", n - count);
		del(root);
	}
	return 0;
}
void insert(struct wocao * root, char *s)
{
	int i;
	struct wocao *temp, *p = root;
	while (*s != '\0')
	{
		if (p->next[*s - 'a'] == NULL)
		{
			temp = (struct wocao *)malloc(sizeof(struct wocao));
			for (i = 0; i < 26; i++)
				temp->next[i] = NULL;
			p->count = 0;
			p->next[*s - 'a'] = temp;
		}
		p = p->next[*s - 'a'];
		s++;
	}
	p->count = 1;
}
int search(struct wocao *root, char *ar)
{
	int i;
	struct wocao *p = root;
	while (*ar != '\0' && p != NULL)
	{
		p = p->next[*ar - 'a'];
		ar++;
	}
	if (p != NULL && p->count == 1)
	{
		p->count = 0;
		return 1;
	}
}

void del(struct wocao *root)
{
	int i;
	for (i = 0; i < 26; i++)
	{
		if (root->next[i] != NULL)
			del(root->next[i]);
	}
	free(root);
}