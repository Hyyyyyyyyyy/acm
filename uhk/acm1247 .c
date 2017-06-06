#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 struct hat
 {
     int sta;
     struct hat *next[26];
 };
 void insert(struct hat *root, char *s);
 int search(struct hat *root, char *s);
 int search1(struct hat *root, char *s);
 void del(struct hat *root);

 int main()
 {
     int i, n = 0;
     struct hat *root;
     char ar[50005][100];

     root = (struct hat *)malloc(sizeof(struct hat));
     root->sta = 0;
     for(i = 0 ; i < 26; i++)
        root->next[i] = NULL;
     while(scanf("%s", ar[n]) != EOF)
     {
        insert(root, ar[n]);
        n++;
     }
     for(i = 0; i < n; i++)
     {
         if(search(root, ar[i]) == 1)
            printf("%s", ar[i]);
        putchar('\n');
     }
     del(root);
     return 0;
 }
 void del(struct hat *root)
 {
     int i;
     for(i = 0; i < 26; i++)
        if(root->next[i] != NULL)
            del(root->next[i]);
    free(root);
 }

void insert(struct hat *root, char *s)
{
    int i;
    struct hat *p = root, *temp;
    while(*s != '\0')
    {
        if(p->next[*s - 'a'] == NULL)
        {
            temp = (struct hat *)malloc(sizeof(struct hat));
            temp->sta = 0;
            for(i = 0; i < 26; i++)
                temp->next[i] =NULL;
            p->next[*s - 'a'] = temp;
        }
        p = p->next[*s - 'a'];
        s++;
    }
}

int search(struct hat *root, char *s)
{
    int i;
    struct hat *p = root;
    while(*s != '\0' && p != NULL)
    {
        p = p->next[*s - 'a'];
        s++;
        if(p->sta == 1 && search1(root, s) == 1)
            return 1;
    }
    return 0;
}

int search1(struct hat *root, char *s)
{
    int i;
    struct hat *p = root;
    while(*s != '\0' && p != NULL)
    {
        p = p->next[*s-'a'];
        s++;
    }
    if(*s == '\0' && p->sta == 1)
        return 1;
    return 0;
}
