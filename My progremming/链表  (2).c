#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film
{
	char title [TSIZE];
	int rating;
	struct film *next;
} ;

char * s_gets(char * st, int n)  //返回一个指针，指向ar数组的开头； 
{
	char * ret_val;
	char * find;
	
	ret_val = fgets(st, n, stdin);
	if(ret_val != NULL)
	{
		find = strchr(st, '\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}

int main()
{	
	struct film *head = NULL;
	struct film *pre, *cur;
	char ar[TSIZE];
	
	while(s_gets(ar, TSIZE) != NULL && ar[0] != '\0')
	{
		cur = (struct film *)malloc(sizeof(struct film)*1);
		cur->next= NULL;
		if(head == NULL)
			head = cur;
		else
			pre->next = cur;
		strcpy(cur->title, ar);
		puts("Enter your rating <0-10>");
		scanf("%d", &cur->rating);
		while(getchar() != '\n')
			continue;
		puts("Enter your next moive title (empty line to stop)");
		pre = cur;
	}	
	if(head == NULL)
		printf("No data entered");
	else
		puts("There is the list");
	cur = head->next;
	while(cur != NULL)
	{
		printf("Moive : %s\nRating: %d\n\n", cur->title, cur->rating);
		cur = cur->next;
	}
	while(cur != NULL)
	{
		if(head == NULL)
		{
			cur = NULL;
			continue;
		}
		cur = head;
		head = cur->next;	
		free(cur);
	}
	printf("Bye\n");
	return 0;
}
