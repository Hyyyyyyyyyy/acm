#include<stdio.h>
#define PRISE "You are an extrodinary being"
int main()
{
    char name[40];
    printf("Hello! What's your name?\n");
    scanf("%s", name);
    printf("%s, %s.\n",name, PRISE);

    return 0;

}
