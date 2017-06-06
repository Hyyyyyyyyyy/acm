#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct goods
{
	int sta;
	int num;
	int id;
	struct goods *next[26];

};
void insert(struct goods *root, char *s, int n);
int search(struct goods *root, char *s);
void del(struct goods *root);
int main()
{
	int i, j, n, m, k, u, L, count;
	char ar[30], sa[30];
	struct goods *root;
	root = (struct goods *)malloc(sizeof(struct goods));
	root->sta = 0;
	root->num = 0;
	root->id = -1;
	for (i = 0; i<26; i++)
		root->next[i] = NULL;
	scanf("%d", &n);
	for (m = 0; m < n; m++)
	{
		scanf("%s", ar);
		L = strlen(ar);
		for(i = 0; i < L; i++)
			insert(root, &ar[i], m);
	}
	scanf("%d", &k);
	for (u = 0; u < k; u++)
	{		
		scanf("%s", sa);	
		printf("%d\n", search(root, sa));
	}
	del(root);
	return 0;
}

void del(struct goods *root)
{
	int i;
	for (i = 0; i < 26; i++)
		if (root->next[i] != NULL)
			del(root->next[i]);
	free(root);
}

void insert(struct goods *root, char *s, int n)
{
	int i;
	struct goods *p = root, *temp;
	while (*s != '\0')
	{
		if (p->next[*s - 'a'] == NULL)
		{
			temp = (struct goods *)malloc(sizeof(struct goods));
			temp->sta = 0;
			temp->num = 1;
			temp->id = n;
			for (i = 0; i < 26; i++)
				temp->next[i] = NULL;
			p->next[*s - 'a'] = temp;
		}
		p = p->next[*s - 'a'];
		if (p->id != n)
		{
			p->num++;
			p->id = n;
		}
		s++;
	}
	p->sta = 1;
}

int search(struct goods *root, char *s)
{
	int i, count = 0;
	struct goods *p = root;
	while (*s != '\0' && p != NULL)
	{
		p = p->next[*s - 'a'];
		s++;
	}
	if (p != NULL)
		return p->num;
	return 0;
}
