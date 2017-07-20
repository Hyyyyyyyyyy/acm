#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <queue>
using namespace std;
const int maxn = 300010;
struct Node
{
    Node *fail;
    Node *next[26];
    int sta;
    Node() {
        fail = NULL;
        memset(next, 0, sizeof(next));
        sta = 0;
    }
};
char s[100];
char ss[1000010];
int N;
void ac_insert(Node *root)
{
    int i, j;
    Node *p = root;
    int L = strlen(s);
    for (i = 0; i < L; i++)
    {
        if (!p->next[s[i] - 'a'])
        {
            Node *temp = new Node;
            p->next[s[i] - 'a'] = temp;
        }
        p = p->next[s[i] - 'a'];
    }
    p->sta++;
}
void ac_buildfail_bfs(Node *root)
{
    queue<Node*>q;
    Node *now;
    Node *after;
    int i, j;
    q.push(root);
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        for (i = 0; i < 26; i++)
        {
            if (now->next[i])
            {
                if (now == root)
                    now->next[i]->fail = root;
                else
                {
                    after = now->fail;
                    while (after)
                    {
                        if (after->next[i])
                        {
                            now->next[i]->fail = after->next[i];
                            break;
                        }
                        after = after->fail;
                    }
                    if (!after)
                    {
                        now->next[i]->fail = root;
                    }
                }
                q.push(now->next[i]);
            }
            else
            {
                if (now == root)
                    now->next[i] = root;
                else
                    now->next[i] = now->fail->next[i];
            }
        }
    }
}
int ac_query(Node *root)
{
    int i, j;
    int cnt = 0;
    int L = strlen(ss);
    Node *p = root;
    for (i = 0; i < L; i++)
    {
        p = p->next[ss[i] - 'a'];
        Node *temp = p;
        while (temp && temp->sta)
        {
            cnt += temp -> sta;
            temp->sta = 0;
            temp = temp->fail;
        }
    }
    return cnt;
}
void del(Node *root)
{
    int i;
    for (i = 0; i < 26; i++)
        if (root->next[i] != NULL)
            del(root->next[i]);
    delete root;
}
int main()
{
    int i, j, k, u, n, m;
    while (scanf("%d", &n) != EOF)
    {
        for (m = 1; m <= n; m++)
        {
            scanf("%d", &N);
            Node *root = new Node;
            for (i = 0; i < N; i++)
            {
                scanf("%s", s);
                ac_insert(root);
            }
            ac_buildfail_bfs(root);
            scanf("%s", ss);
            printf("%d\n", ac_query(root));
            //del(root);
        }
    }
    return 0;
}