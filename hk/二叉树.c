#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
	struct Node* l;
	struct Node* r;
	char s;
};
void build(struct Node* root)
{
	scanf("%c", &root->s);
	root->l = NULL;
	root->r = NULL;
	if (root->s == '0')
		return;
	root->l = (struct Node*)malloc(sizeof(struct Node));
	root->r = (struct Node*)malloc(sizeof(struct Node));
	build(root->l);
	build(root->r);
}
void print1(struct Node* root)
{
	if (root->s == '0')
		return;
	printf("%c", root->s);
	print1(root->l);
	print1(root->r);
}
void print2(struct Node* root)
{
	if (root->s == '0')
		return;
	print2(root->l);
	printf("%c", root->s);
	print2(root->r);
}
void print3(struct Node* root)
{
	if (root->s == '0')
		return;
	print3(root->l);
	print3(root->r);
	printf("%c", root->s);
}
int main()
{
	struct Node * root = NULL;
	int i, j, N, n, m;
	scanf("%d", &n);
	getchar();
	for (m = 1; m <= n; m++)
	{
		root = (struct Node*)malloc(sizeof(struct Node));
		N = 0;
		build(root);
		getchar();
		print1(root);
		putchar('\n');
		print2(root);
		putchar('\n');
		print3(root);
		if(m != n)
			putchar('\n');
	}
	return 0;
}
