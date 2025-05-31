/*The code returns "0" if the given string is in alphabetical order else it returns the index number from where the alphabetical order starts to break*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/* only used in string related operations */
typedef struct String string;
struct String
{
    char *str;
};

char *input(FILE *fp, int size, int has_space)
{
    int actual_size = 0;
    char *str = (char *)malloc(sizeof(char)*(size+actual_size));
    char ch;
    if(has_space == 1)
    {
        while(EOF != (ch=fgetc(fp)) && ch != '\n')
        {
            str[actual_size] = ch;
            actual_size++;
            if(actual_size >= size)
            {
                str = realloc(str,sizeof(char)*actual_size);
            }
        }
    }
    else
    {
        while(EOF != (ch=fgetc(fp)) && ch != '\n' && ch != ' ')
        {
            str[actual_size] = ch;
            actual_size++;
            if(actual_size >= size)
            {
                str = realloc(str,sizeof(char)*actual_size);
            }
        }
    }
    actual_size++;
    str = realloc(str,sizeof(char)*actual_size);
    str[actual_size-1] = '\0';
    return str;
}
/* only used in string related operations */


/*
 * inputSting, represents the given string.
 */
int funcAlphabeticOrder(struct String inputSting)
{
    int i;
    int len = strlen(inputSting.str);

    for(i = 0; i < len - 1; i++) {
        if(inputSting.str[i] > inputSting.str[i + 1]) {
            return i+1;  // Found the first index where order breaks
        }
    }

    return 0; // String is in alphabetical order
}


int main()
{
    struct String inputSting;
	
    
	//input for inputSting
	inputSting.str = input(stdin, 100, 1);
	
	
    int result = funcAlphabeticOrder(inputSting);
	printf("%d", result);
	
    return 0;
}
