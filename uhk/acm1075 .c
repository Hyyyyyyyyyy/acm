#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
struct dict
{
	int sta;
	struct dict *next[26];
	char sg[15];
};
void insert(struct dict *root, char *s, char *f);
void search(struct dict *root, char *s);
void del(struct dict *root);

int main()
{
	int i, j, k, u, n, m, L;
	struct dict *root;
	char ar[10000000], *p;
	char sa[15], sd[15], sf[15];
	root = (struct dict *)malloc(sizeof(struct dict));
	for (i = 0; i < 26; i++)
		root->next[i] = NULL;
	root->sta = 0;

	scanf("%s", sd);
	while (scanf("%s", sa) != EOF && strcmp(sa, "END") != 0)
	{
		scanf("%s", sd);
		insert(root, sd, sa);
	}
	scanf("%s", sd);
	getchar();
	while(fgets(ar,10000000, stdin) != NULL && strcmp(ar, "END\n") != 0)
	{
		j = 0;
		L = strlen(ar);
		for (i = 0; i < L; i++)
		{
			if (isalpha(ar[i]))
			{
				sf[j] = ar[i];
				j++;
			}
			else
			{
				sf[j] = '\0';
				search(root, sf);
				putchar(ar[i]);
				j = 0;
			}
		 }
	}
	del(root);
	return 0;
}
void del(struct dict *root)
{
	int i;
	for (i = 0; i < 26; i++)
	{
		if (root->next[i] != NULL)
			del(root->next[i]);
	}
	free(root);
}
void insert(struct dict *root, char *s, char *f)
{
	int i, j;
	struct dict *temp, *p = root;
	char *q = f;
	while (*s != '\0')
	{
		if (p->next[*s - 'a'] == NULL)
		{
			temp = (struct dict *)malloc(sizeof(struct dict));
			for (i = 0; i < 26; i++)
				temp->next[i] = NULL;
			temp->sta = 0;

			p->next[*s - 'a'] = temp;
		}
		p = p->next[*s - 'a'];
		s++;
	}
	p->sta = 1;
	strcpy(p->sg, q);
}
void search(struct dict *root, char *s)
{
	int i;
	struct dict *p = root;
	char *q = s;
	while (*q != '\0' && p != NULL)
	{
		p = p->next[*q - 'a'];
		q++;
	}
	if (p != NULL && p->sta == 1)
		printf("%s", p->sg);
	else if(*s != '\0')
		printf("%s", s);
}
