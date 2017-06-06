#include <stdio.h>
#include <stdlib.h>
struct binary
{
	int sta;
	struct binary* next[2];
};
int insert(struct binary *root, char *ar);
void del(struct binary *root);
int main()
{
	int i, doudou = 0, cas = 0;
	char ar[50];
	struct binary *root = (struct binary *)malloc(sizeof(struct binary));
	for (i = 0; i < 2; i++)
	{
		root->next[i] = NULL;
	}
	root -> sta = 0;
	while (scanf("%s", ar) != EOF)
	{
		if (ar[0] == '9')
		{
			cas++;
			if (doudou == 0)
				printf("Set %d is immediately decodable\n", cas);
			else
				printf("Set %d is not immediately decodable\n", cas);
			continue;
		}
		getchar();

		if (insert(root, ar))
			doudou = 1;
		else
			doudou = 0;
	}


	return 0;
}

int insert(struct binary *root, char *ar)
{
	int i, doudou = 0;
	struct binary *p, *temp;
	p = root;

	while (*ar != '\0')
	{
		if (p->next[*ar - '0'] == NULL)
		{
			if (p->sta == 1)
				doudou = 1;
			temp = (struct binary *)malloc(sizeof(struct binary));
			for (i = 0; i < 2; i++)
				temp->next[i] = NULL;
			temp->sta = 0;
			p->next[*ar - '0'] = temp;
		}
		else
		{
			if (*(ar + 1) == '\0')
				doudou = 1;
		}
		p = p->next[*ar - '0'];
		ar++;
	}
	p->sta = 1;
	return doudou;
}
