#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


char* user_strcat(char* str1, char* str2);

int main(int argc, char* argv[]) {

    char buff[80];
    if(argc != 3)
        printf(" Usage : %s str1 str2\n", argv[0]);
    
    user_strcat(argv[1], argv[2]);
    printf("연결된 문자열 : %s\n", argv[1]);
	return 0;
}


char* user_strcat(char* str1, char* str2)
{
	char* temp = str1;
	while (*str1 != '\0') 
		str1++;
	
	while (*str2 != '\0'){
		*(str1++) = *(str2++);
	}
	
	*str1 = '\0';
	return temp;
}
