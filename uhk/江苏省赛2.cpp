#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Node
{
    int v;
    Node *left, *right;
};
int ans[100005];
int x, n;
void settree(Node *node, int now)
{
        Node *p = node;
        p->v = now;
        if(now * 2 <= n)
        {
            Node *q;
            q = (Node*)malloc(sizeof(Node));
            q->left = NULL;
            q->right = NULL;
            p->left = q;
            settree(p->left, now * 2);
        }
        if(now * 2 + 1 <= n)
        {
            Node *q;
            q = (Node*)malloc(sizeof(Node));
            q->left = NULL;
            q->right = NULL;
            p->right = q;
            settree(p->right, now * 2 + 1);
        }
}
int cnt;
void print(Node *node)
{
    Node *p = node;
    printf("%d\n", p->v);
    if(p->left != NULL)
        print(p->left);
    if(p->right != NULL)
        print(p->right);
}
void solve(Node *node)
{
    Node *p = node;
    if(p->left != NULL)
        solve(p->left);
    ans[cnt++] = p->v;
    if(p->right != NULL)
        solve(p->right);
}
int main()
{
    int t;
    scanf("%d", &t);
    int kase = 1;
    while(t--)
    {
        cnt = 1;
        memset(ans, 0, sizeof(ans));
        scanf("%d%d", &n, &x);
        Node *node;
        node = (Node*)malloc(sizeof(Node));
        node->left = NULL;
        node->right = NULL;
        settree(node, 1);
 //       print(node);
        solve(node);
        printf("Case #%d: %d\n", kase++, ans[x]);
    }
    return 0;
}