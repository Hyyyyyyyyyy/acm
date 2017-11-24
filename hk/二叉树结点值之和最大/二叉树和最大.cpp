#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const int maxn = 1000000 + 100;
int N;
struct TreeNode
{
	int val;
	int sum;
	struct TreeNode* left;
	struct TreeNode* right;
};
TreeNode* NewNode()
{
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	if (!root)
		return 0;
	root->left = NULL;
	root->right = NULL;
	root->val = 0;
	root->sum = 0;
	return root;
}
void Pushup(struct TreeNode* root)
{
	int Max = (root)->val;
	int LeftSum = (root)->left->sum;
	int RightSum = (root)->right->sum;
	int TempSum = (root)->val;
	if (Max < LeftSum + RightSum)
		Max = LeftSum + RightSum;
	if ((root)->left->val)
	{
		TempSum += (root)->left->left->sum;
		TempSum += (root)->left->right->sum;
	}
	if ((root)->right->val)
	{
		TempSum += (root)->right->left->sum;
		TempSum += (root)->right->right->sum;
	}
	if (Max < TempSum)
		Max = TempSum;
	(root)->sum = Max;
}
int Build(struct TreeNode* root)
{
	if (!root)
		return 0;
	scanf("%d", &((root)->val));
	if ((root)->val)
	{
		(root)->left = NewNode();
		if (!Build(((root)->left)))
			return 0;
		(root)->right = NewNode();
		if (!Build(((root)->right)))
			return 0;
		Pushup(root);
	}
	else
		(root)->sum = (root)->val;
	return 1;
}
int Destroy(TreeNode* root)
{
	if (!root)
		return 0;
	if (root->left)
		Destroy(root->left);
	if (root->right)
		Destroy(root->right);
	free(root);
	return 1;
}
int main()
{
	//freopen("IN.txt", "r", stdin);
	int i, j, n, m;
	struct TreeNode* root;
	printf("                                  ***********************************************\n");
	printf("                                  *                  Menu                       *\n");
	printf("                                  *                0.Build                      *\n");
	printf("                                  *                1.Show                       *\n");
	printf("                                  *                2.Destroy                    *\n");
	printf("                                  *                3.Exit                       *\n");
	printf("                                  ***********************************************\n");
	while (scanf("%d", &n) != EOF && n != 3)
	{
		switch (n)
		{
		case 0:
		{
			root = NewNode();
			if (Build(root))
			{
				printf("Yes. Build successfully!\n");
			}
			else
				printf("Sorry. Build failed!\n");
			break;
		}
		case 1:
		{
			if (root)
				printf("The max sum of the tree is %d!\n", root->sum);
			else
				printf("Sorry. No tree!\n");
			break;
		}
		case 2:
		{
			if (Destroy(root))
				printf("Yes. Destroy successfully!\n");
			else
				printf("Sorry. Destroy failed\n");
			break;
		}
		default:
			printf("Please input intger number 0~3.\n");
		}
	}
	return 0;
}