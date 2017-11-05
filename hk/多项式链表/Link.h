#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
const int maxn = 100005;
int NumPolyns;		//用户输入的多项式有多少项
char StackS[5];   //字母栈
double StackCoe;     //系数栈
double StackTi;      //次数栈
struct Node
{
	Node *Next;
	double coe;        //系数
	double time;       //次数
	char ch;
};
struct Polyn
{
	Node* root;
	Polyn() {
		root = NULL;
	}
};
bool NewNode0(Node *P)			//为新节点初始化，下同
{
	P->coe = 0;
	P->time = maxn + 10;
	P->ch = StackS[0];
	P->Next = NULL;
	return (P == NULL ? false : true);
}
bool NewNode1(double c, double t, char s, Node*P)
{
	P->coe = c;
	P->time = t;
	P->ch = s;
	P->Next = NULL;
	return (P == NULL ? false : true);
}
bool NewNode2(double c, double t, char s, Node*N, Node*P)
{
	P->coe = c;
	P->time = t;
	P->ch = s;
	P->Next = N;
	return (P == NULL ? false : true);
}
Node* Find(Node* root, double ti)      //在p后面加新结点
{
	if (!root)
		return NULL;
	Node* p = root;
	while (p->Next && p->Next->time > ti)
	{
		p = p->Next;
	}
	return p;
}
Node* Merge(Node* root)     //合并同类项，并删除系数为0且指数不为0的项
{
	if (!root)
		return NULL;
	if (!root->Next)
		return NULL;
	Node* p = root;
	char s = p->Next->ch;
	while (p->Next->Next)
	{
		if (p->Next->time == p->Next->Next->time)
		{
			p->Next->coe += p->Next->Next->coe;
			p->Next->Next = p->Next->Next->Next;
		}
		else
			p = p->Next;
	}
	p = root;
	while (p->Next)
	{
		if (p->Next->coe == 0 && p->Next->time != 0)
		{
			p->Next = p->Next->Next;
		}
		else
			p = p->Next;
	}
	if (!root->Next)
	{
		root->Next = (Node*)malloc(sizeof(Node));
		NewNode1(0, 0, s, root->Next);
	}
	return root;
}
Node* CreatPolyn(Node *root)     //按次数从小到大创建
{
	root = (Node*)malloc(sizeof(Node));
	NewNode0(root);
	Node* p = root;
	Node* q;
	int i, j;
	char ch;
	printf("What is it related to?\n");
	scanf("%s", StackS);
	printf("Please input how many terms do you want:\n");
	scanf("%d", &NumPolyns);
	printf("Please input polyns:(A, B)\n");

	for (i = 1; i <= NumPolyns; i++)
	{
		scanf("%lf %lf", &StackCoe, &StackTi);
		p = Find(root, StackTi);
		q = (Node*)malloc(sizeof(Node));
		NewNode2(StackCoe, StackTi, StackS[0], p->Next, q);
		p->Next = q;
	}
	Merge(root);
	return root;
}
bool PrintPolyn(Node *root)			//打印，先打印系数，再指数
{
	if (!root)
		return false;
	if (!root->Next)
		return false;
	bool Flag = false;
	Node* p = root->Next;
	while (p)
	{
		if (p->coe < 0)
		{
			if (p->coe != -1)
				printf("%.1f", p->coe);
			else
				printf("-");
		}
		else if (p->coe > 0)
		{
			if (Flag)
			{
				if (p->coe != 1)
					printf("+%.1f", p->coe);
				else
					printf("+");
			}
			else
			{
				if (p->coe != 1)
					printf("%.1f", p->coe);
			}
		}
		else
		{
			if (!Flag)
				printf("0.0");
			break;
		}
		if (p->time > 1 || p->time <= -1)
		{
			printf("%c", p->ch);
			printf("^");
			printf("%.1f", p->time);
		}
		else if (p->time == 1)
		{
			printf("%c", p->ch);
		}
		else
		{
			if (Flag)
			{
				if (p->coe > 0)
					printf("%.1f", p->coe);
				else
					printf("%.1f", -p->coe);
			}
			else
			{
				if (p->coe != 0)
					printf("%.1f", fabs(p->coe));
			}
		}
		p = p->Next;
		Flag = true;
	}
	putchar('\n');
}
Node* AddPolyn(Node* root1, Node* root2)			//root1+root2
{
	if (!root1 || !root2)
		return NULL;
	if (!root1->Next || !root2->Next)
		return NULL;
	Node* p1 = root1;
	Node* p2 = root2;
	Node* root3;
	root3 = (Node*)malloc(sizeof(Node));
	NewNode0(root3);
	Node* p3 = root3;
	while (p1->Next && p2->Next)
	{
		if (p1->Next->ch != p2->Next->ch)
			return NULL;
		if (p1->Next->time > p2->Next->time)
		{
			p3->Next = (Node*)malloc(sizeof(Node));
			NewNode1(p1->Next->coe, p1->Next->time, p1->Next->ch, p3->Next);
			p3 = p3->Next;
			p1 = p1->Next;
		}
		else
		{
			p3->Next = (Node*)malloc(sizeof(Node));
			NewNode1(p2->Next->coe, p2->Next->time, p2->Next->ch, p3->Next);
			p3 = p3->Next;
			p2 = p2->Next;
		}
	}
	while (p1->Next)
	{
		p3->Next = (Node*)malloc(sizeof(Node));
		NewNode1(p1->Next->coe, p1->Next->time, p1->Next->ch, p3->Next);
		p3 = p3->Next;
		p1 = p1->Next;
	}
	while (p2->Next)
	{
		p3->Next = (Node*)malloc(sizeof(Node));
		NewNode1(p2->Next->coe, p2->Next->time, p2->Next->ch, p3->Next);
		p3 = p3->Next;
		p2 = p2->Next;
	}
	return Merge(root3);
}
bool Opposite(Node* root)				//root取反
{
	if (!root)
		return NULL;
	if (root->Next == NULL)
		return false;
	Node* p = root->Next;
	while (p)
	{
		p->coe *= -1;
		p = p->Next;
	}
	return true;
}
Node* SubtractPolyn(Node* root1, Node* root2)				//root1-root2
{
	if (!root1 || !root2)
		return NULL;
	if (!root1->Next || !root2->Next)
		return NULL;
	Node* p = root1;
	if (Opposite(root2))
	{
		p = AddPolyn(root1, root2);
		Opposite(root2);
	}
	return p;
}
Node* MultiplyPolyn(Node* root1, Node* root2)		//root1*root2
{
	if (!root1 || !root2)
		return NULL;
	if (!root1->Next || !root2->Next)
		return NULL;
	Node* p1 = root1;
	Node* p2 = root2;
	Node* root3;
	root3 = (Node*)malloc(sizeof(Node));
	NewNode0(root3);
	Node* p3 = root3;
	Node* q;
	double Ti, Coe;
	while (p1->Next)
	{
		while (p2->Next)
		{
			if (p1->Next->ch != p2->Next->ch)
				return NULL;
			Ti = p1->Next->time + p2->Next->time;
			Coe = p1->Next->coe * p2->Next->coe;
			p3 = Find(root3, Ti);
			q = (Node*)malloc(sizeof(Node));
			NewNode2(Coe, Ti, p1->Next->ch, p3->Next, q);
			p3->Next = q;
			p2 = p2->Next;
		}
		p1 = p1->Next;
		p2 = root2;
	}
	Merge(root3);
	return root3;
}
bool DeletePolyns(Node* root)			//删除root链表
{
	if (!root)
		return false;
	Node* p;
	while (root->Next)
	{
		p = root;
		root = root->Next;
		free(p);
	}
	free(root);
	return true;
}