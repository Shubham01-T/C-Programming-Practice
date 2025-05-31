/*The given code finds the longest palindrome substring from the given string */
//Header Files
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
 * inputStr, represents the given string for the puzzle
 */
void funcSubstring(string inputStr)
{
    int start = 0;
    int maxLength = 1;
    int len = strlen(inputStr.str);

    for (int i = 0; i < len; i++) {
        // Odd length palindrome
        int left = i, right = i;
        while (left >= 0 && right < len && inputStr.str[left] == inputStr.str[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }
            left--;
            right++; 
        }

        // Even length palindrome
        left = i;
        right = i + 1;
        while (left >= 0 && right < len && inputStr.str[left] == inputStr.str[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }
            left--;
            right++;
        }
    }

    // Only print if length is greater than 1
    if (maxLength > 1) {
        for (int i = start; i < start + maxLength; i++) {
            putchar(inputStr.str[i]);
        }
        printf("\n");
    }
    else{
        printf("None\n");
    }
}



int main()
{
    string inputStr;
	
    
	//input for inputStr
	inputStr.str = input(stdin, 100, 1);
	
	
    
	funcSubstring(inputStr);
    return 0;
}
