#include <stdio.h>
#include <string.h>
#define love1 "You love rainy"
#define love2 "I am your rain"
#define love3 "I love sunny"
#define love4 "You are my sun"
#define love5 "We love each other"
#define love6 "But we are in diferent"
#define love7 "So So So So So So So So So So So"
#define FOREVER 49
#define BLANK ' '

void show_n_char(char ch, int num);

int main()
{
    int spaces;

    show_n_char('*', FOREVER);
    putchar('\n');
    spaces = (FOREVER - strlen(love1)) / 2;
    show_n_char(BLANK, spaces);
    printf("%s\n", love1);

    spaces = (FOREVER - strlen(love2)) / 2;
    show_n_char(BLANK, spaces);
    printf("%s\n", love2);

    spaces = (FOREVER - strlen(love3)) / 2;
    show_n_char(BLANK, spaces);
    printf("%s\n", love3);

    spaces = (FOREVER - strlen(love4)) / 2;
    show_n_char(BLANK, spaces);
    printf("%s\n", love4);

    spaces = (FOREVER - strlen(love5)) / 2;
    show_n_char(BLANK, spaces);
    printf("%s\n", love5);

    spaces = (FOREVER - strlen(love6)) / 2;
    show_n_char(BLANK, spaces);
    printf("%s\n", love6);

    spaces = (FOREVER - strlen(love7)) / 2;
    show_n_char(BLANK, spaces);
    printf("%s\n", love7);

    show_n_char('*', FOREVER);
    putchar('\n');

    return 0;
}

void show_n_char(char ch, int num)
{
    int count;
    for (count = 1; count <= num; count++)
        putchar(ch);
}
