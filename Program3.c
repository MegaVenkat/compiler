//Program to to recognize a token (RELOP)
#include <stdio.h>
#include <string.h>
struct Token
{
    char *token;
    char *attribute;
};

void fail()
{
    printf("Lexical Error : Invalid Character.");
}
struct Token ques(char *str)
{
    int state = 0, i = 0, len;
    struct Token t;
    len = strlen(str);
    while (1)
    {
        char ch = str[i++];
        switch (state)
        {
        case 0:
        {
            if (ch == '<')
                state = 1;
            else if (ch == '=')
                state = 5;
            else if (ch == '>')
                state = 6;
            else
                fail();
            break;
        }
        case 1:
        {
            if (ch == '=')
                state = 2;
            else if (ch == '>')
                state = 3;
            else
                state = 4;
            break;
        }
        case 2:
        {
            t.token = "RELOP";
            t.attribute = "LE";
            return t;
        }
        case 3:
        {
            t.token = "RELOP";
            t.attribute = "NE";
            return t;
        }
        case 4:
        {
            t.token = "RELOP";
            t.attribute = "LT";
            return t;
        }
        case 5:
        {
            t.token = "RELOP";
            t.attribute = "EQ";
            return t;
        }
        case 6:
        {
            if (ch == '=')
                state = 7;
            else
                state = 8;
            break;
        }
        case 7:
        {
            t.token = "RELOP";
            t.attribute = "GE";
            return t;
        }

        case 8:
        {
            t.token = "RELOP";
            t.attribute = "GT";
            return t;
        }
        }
    }
}
int main()
{
    char str[100];
    printf("Enter a string : ");
    scanf("%s", str);
    struct Token p = ques(str);
    printf("%s %s", p.token, p.attribute);
    return 0;
}
