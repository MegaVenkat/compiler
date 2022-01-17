//Program to accept Regular expressions : abb*
#include <stdio.h>
#include <string.h>
int main ()
{
  int i,state = 0;
  char str[100];
  printf("Enter a string : ");
  gets(str);
  if (str[0] != 'a' || strlen(str)<2);
  else
    {
      for (i = 1; i < strlen(str); i++)
	{
	  
	  if (str[i] == 'b')
	    state = 2;
	    else
	    {
	        state=1;
	        break;
	    }
	}
    }
  if (state == 2)
    printf("Accepted " );
  else
    printf("Not accepted") ;
  return 0;
}


