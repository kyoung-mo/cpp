#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* user_strcat(char* str1, const char* str2);  //0x100, 0x200
int main(int argc, char* argv[])
{
//	char fruit[80] = "straw";
	char buff[80];
	if(argc != 3)
	{
		printf(" Usage : %s str1 str2\n",argv[0]);
		exit(1);
	}

	strcpy(buff,argv[1]);
	user_strcat(buff, argv[2]);  //0x100, 0x200
	printf("연결된 문자열 : %s\n", buff);

//	user_strcat(fruit, "berry");  //0x100, 0x200
//	printf("연결된 문자열 : %s\n", fruit);
//	printf("연결된 문자열 : %s\n", user_strcat(fruit, "berry"));
	return 0;
}

char* user_strcat(char* str1, const char* str2)  //0x100, 0x200
{
	char* temp = str1;
	while(*str1 != '\0')
		str1++;			//str1 = str1 + 1;
	while (*str2 != '\0')
	{
		*str1 = *str2;
	//	*str2 = *str1;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return temp;
}
