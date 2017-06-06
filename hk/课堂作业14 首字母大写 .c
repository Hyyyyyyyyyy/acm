#include <stdio.h>
#include <ctype.h>
int main()
{
    int i;
    char word[100];

	//输入部分 
	printf("Please enter a sentence we help you correct ");
	printf("if the first letter is a lower-case letter\n");
    for (i = 0;; i++)
    {
        scanf("%c", &word[i]);
        word[0] = toupper(word[0]);
        if (word[i-1] == ' ' || word[i-1] == '.' || word[i-1] == '"')
            word[i] = toupper(word[i]);
        if (word[i] == '\n')
            break; 
    }
    //输出部分 
    for (i = 0; i <= 100; i++)
    {
        printf("%c", word[i]);
        if (word[i] == '\n')
        	break;
    }
    return 0;
}
