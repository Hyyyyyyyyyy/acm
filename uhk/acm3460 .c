#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct print
{

	struct print * next[26];
};
void insert(struct print * root, char *s, long long int *S);
void del(struct print *root);
int main()
{
	int i, j, n, m, L, maxl;
	char ar[55];
	long long sum, *S;
	struct print *root;
	while (scanf("%d", &n) != EOF)
	{
		sum = 0;
		maxl = 0;
		S = &sum;
		root = (struct print *)malloc(sizeof(struct print));
		for (i = 0; i < 26; i++)
			root->next[i] = NULL;

		for (m = 1; m <= n; m++)
		{
			scanf("%s", ar);
			if (maxl < (L = strlen(ar)))
				maxl = L;
			insert(root, ar, S);
		}
		printf("%lld\n", sum - maxl + n);
		del(root);
	}

	return 0;
}
void del(struct print *root)
{
	int i;
	for (i = 0; i < 26; i++)
		if (root->next[i] != NULL)
			del(root->next[i]);
	free(root);
}
void insert(struct print * root, char *s, long long  int *S)
{
	int i;
	struct print *temp, *p = root;
	while (*s != '\0')
	{
		if (p->next[*s - 'a'] == NULL)
		{
			temp = (struct print *)malloc(sizeof(struct print));
			for (i = 0; i < 26; i++)
				temp->next[i] = NULL;
			*S += 2;
			p->next[*s - 'a'] = temp;
		}
		p = p->next[*s - 'a'];
		s++;
	}
}
