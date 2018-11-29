#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
const int maxn = 100005;
int NumPolyns;
char S[maxn];
char StackS;      //字母栈
int StackCoe;     //系数栈
int StackTi;      //次数栈
char StackF;      //符号栈
struct Node
{
    Node *Next;
    int coe;        //系数
    int time;       //次数
    char ch;
};
struct Polyn
{
    Node* root;
};
bool NewNode0(Node *P)
{
    P->coe = 0;
    P->time = 0;
    P->ch = 'x';
    P->Next = NULL;
    return (P == NULL ? false:true);
}
bool NewNode1(int c, int t, char s, Node*P)
{
    P->coe = c;
    P->time = t;
    P->ch = s;
    P->Next = NULL;
    return (P == NULL ? false:true);
}
bool NewNode2(int c, int t, char s, Node*N, Node*P)
{
    P->coe = c;
    P->time = t;
    P->ch = s;
    P->Next = N;
    return (P == NULL ? false:true);
}
Node* Find(Node* root, int ti)      //在p后面加新结点
{
    Node* p = root;
    int i, j, k;
    while(p->Next && p->Next->time < ti)
    {
        p = p->Next;
    }
    return p;
}
Node* Merge(Node* root)     //合并同类项
{
    Node* p = root;
    int i, j, k;
    while(p->Next)
    {
        if(p->Next->time == p->Next->Next->time)
        {
            p->Next->coe += p->Next->Next->coe;
            p->Next->Next = p->Next->Next->Next;
        }
        else
            p = p->Next->Next;
    }
    p = root;
    while(p->Next)
    {
        if(p->Next->coe == 0)
        {
            p->Next = p->Next->Next;
        }
        else
            p = p->Next;
    }
    return root;
}
bool CreatPolyn(Node *root)     //按次数从小到大创建
{   
    root = (Node*)malloc(sizeof(Node));
    NewNode0(root);
    Node* p = root;
    Node* q;
    int i, j, Len, coe, ti;
    char ch;
    printf("Please input how many polyns do you want:\n");
    scanf("%d", NumPolyns);
    printf("Please input polyns:(A, B)\n");

    for(i = 1; i <= NumPolyns; i++)
    {
        scanf("%d %d", &StackCoe)
        StackTi = ;
        p = Find(root, StackTi);
        q = (Node*)malloc(sizeof(Node));
        NewNode2(StackCoe*StackF, StackTi, StackS, p->Next, q);
        p->Next = q;
        StackF = (S[i] == '+' ? 1:-1);
        StackS = 0;
        continue;
    }
    Merge(root);
    return true;
}
void PrintPolyn(Node *root)
{
    if(root->Next == NULL)
    {
        printf("No such Polyn\n");
        return;
    }
    Node* p = root->Next;
    while(p)
    {
        if(p->coe < 0)
        {
            printf("-");
        }
        else if(p->coe > 0)
        {
            printf("+");
        }
        if(p->time > 1)
        {
            printf("%c", p->ch);
            printf("^");
            printf("%d", p->time);
        }
        else if(p->time == 1)
        {
            printf("%c", p->ch);
        }
        p = p->Next;
    }
    putchar('\n');
}
Node* AddPolyn(Node* root1, Node* root2)
{
    Node* p1 = root1;
    Node* p2 = root2;
    Node* root3;
    NewNode0(root3);
    Node* p3 = root3;
    while(p1->Next && p2->Next)
    {
        if(p1->Next->time < p2->Next->time)
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
    while(p1->Next)
    {
        p3->Next = (Node*)malloc(sizeof(Node));
        NewNode1(p1->Next->coe, p1->Next->time, p1->Next->ch, p3->Next);
        p3 = p3->Next;
        p1 = p1->Next;
    }
    while(p2->Next)
    {
        p3->Next = (Node*)malloc(sizeof(Node));
        NewNode1(p2->Next->coe, p2->Next->time, p2->Next->ch, p3->Next);
        p3 = p3->Next;
        p2 = p2->Next;
    }
    return Merge(root3);
}
bool Opposite(Node* root)
{
    int i, j, k;
    if(root->Next == NULL)
        return false;
    Node* p = root->Next;
    while(p)
    {
        p->coe *= -1;
        p = p->Next;
    }
    return true;
}
Node* SubtractPolyn(Node* root1, Node* root2)
{
    Node* p = NULL;
    if(Opposite(root2))
    {
        p = AddPolyn(root1, root2);
        Opposite(root2);
    }
    return p;
}
Node* MultiplyPolyn(Node* root1, Node* root2)
{
    Node* p1 = root1;
    Node* p2 = root2;
    Node* root3;
    NewNode0(root3);
    Node* p3 = root3;
    Node* q;
    int Ti, Coe, i, j, k;
    while(p1->Next)
    {
        while(p2->Next)
        {
            Ti = p1->Next->time + p2->Next->time;
            Coe = p1->Next->coe * p2->Next->coe;
            p3 = Find(root3, Ti);
            q = (Node*)malloc(sizeof(Node));
            NewNode2(Coe, Ti, StackS, p3->Next, q);
            p3->Next = q;
            p2 = p2->Next;
        }
        p1 = p1->Next;
    }
    while(p1->Next)
    {
        p3 = Find(root3, p1->Next->time);
        q = (Node*)malloc(sizeof(Node));
        NewNode2(p1->Next->coe, p1->Next->time, p1->Next->ch, p3->Next, q);
        p3->Next = q;
        p1 = p1->Next;
    }
    while(p2->Next)
    {
        p3 = Find(root3, p2->Next->time);
        q = (Node*)malloc(sizeof(Node));
        NewNode2(p2->Next->coe, p2->Next->time, p2->Next->ch, p3->Next, q);
        p3->Next = q;
        p2 = p2->Next;
    }
    Merge(root3);
    return root3;
}
