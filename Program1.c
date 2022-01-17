//Program to accept Regular expressions : abb*cd+
#include <stdio.h>
#include <string.h>
int main()
{
    char ch[100];
    int state = 1, i = 0, t = 0, len;
    printf("Enter a string : ");
    gets(ch);
    len = strlen(ch);
    
    if (strlen(ch) < 4 || ch[0] != 'a' || ch[1] != 'b' || ch[strlen(ch) - 1] != 'd')
        state = 6;
    else
    {
        while (i < len && t != 1)
        {
            switch (state)
            {
            case 1:
                if (ch[i] == 'a')
                {
                    state = 2;
                    i++;
                }
                else
                    t = 1;
                break;
            case 2:
                while (ch[i] == 'b')
                {
                    state = 3;
                    i++;
                }
                break;
            case 3:
                if (ch[i] == 'c')
                {
                    state = 4;
                    i++;
                }
                else
                    t = 1;
                break;
            case 4:
                while (ch[i] == 'd')
                {
                    state = 5;
                    i++;
                }
                if (ch[i] != 'd')
                    t = 1;
                break;
            default:
                state = 6;
                break;
            }
        }
    }
    if (state == 5)
        printf("Accepted");
    else
        printf("Rejected");

    return 0;
}
