#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct lily
{
    int sta;
    struct lily *next[26];

};
int insert(struct lily * root, char *s);
void del(struct lily *root);
int main()
{
    int i, j, L, count;
    char ar[100], sf[100];
    struct lily *root;
    while (fgets(ar, 1000000, stdin) != NULL && ar[0] != '#')
    {
        root = (struct lily *)malloc(sizeof(struct lily));
        root->sta = 0;
        for (i = 0; i < 26; i++)
            root->next[i] = NULL;
        L = strlen(ar);
        j = 0;
        count = 0;
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
                if (insert(root, sf) == 1)
                    count++;
                j = 0;
            }
        }
        printf("%d\n", count);
        del(root);
    }
    
    return 0;
}
void del(struct lily *root)
{
    int i;
    for (i = 0; i < 26; i++)
    {
        if (root -> next[i] != NULL)
            del(root->next[i]);
    }
    free(root);
}

int insert(struct lily * root, char *s)
{
    int i;
    struct lily *p = root, *temp;
    while (*s != '\0')
    {
        if (p->next[*s - 'a'] == NULL)
        {
            temp = (struct lily *)malloc(sizeof(struct lily));
            temp->sta = 0;
            for (i = 0; i < 26; i++)
                temp->next[i] = NULL;
            p->next[*s - 'a'] = temp;

        }
        p = p->next[*s - 'a'];
        s++;

    }
    if (p->sta == 1 || p == root)
        return 0;
    else
    {
        p->sta = 1;
        return 1;
    }
}
