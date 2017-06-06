#include <stdio.h>
#include <stdlib.h>
struct pre
{
    int count;
    struct pre *next[26];
};
void insert(struct pre *root, char *ar);
int search(struct pre *root, char *ar);
void del(struct pre *root);
int main()
{
    int i, j, n, m;
    char ar[11];
    struct pre * root;
    root = (struct pre *)malloc(sizeof(struct pre));
    for (i = 0; i < 26; i++)
    {
        root->next[i] = NULL;
    }
    root->count = 0;
    while (gets(ar) != NULL && ar[0] != '\0')
    {
        insert(root, ar);
    }
    while (gets(ar) != NULL && ar[0] != '\0')
    {
        printf("%d\n", search(root, ar));
    }
    del(root);
    return 0;
}

void insert(struct pre *root, char *ar)
{
    int i, c;
    struct pre *p = root, *temp;
    while (*ar != '\0')
    {
        if (p -> next[*ar - 'a'] == NULL)
        {
            temp = (struct pre *)malloc(sizeof(struct pre));
            for (i = 0; i < 26; i++)
            {
                temp->next[i] = NULL;
            }
            temp->count = 0;
            p -> next[*ar - 'a'] = temp;
        }
        p = p->next[*ar - 'a'];
        p->count++;
        ar++;
    }
}

int search(struct pre *root, char *ar)
{
    int i;
    struct pre *p = root;
    while (*ar != '\0' && p != NULL)
    {
        p = p->next[*ar - 'a'];
        if (*(ar + 1) == '\0' && p != NULL)
            return p->count;
        ar++;
    }
    if (p == NULL)
        return 0;
}

void del(struct pre *root)
{
    int i;
    for (i = 0; i < 26; i++)
    {
        if (root->next[i] != NULL)
            del(root->next[i]);
    }
    free(root);
}