#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* user_strcat(char* str1, char* str2)
{
	char* temp = str1;
	while (*str1 != '\0') 
		str1++;
	
	while (*str2 != '\0'){
		*(str1++) = *(str2++);
		//*str1 = *str2;
		//str1++;
		//str2++;
	}
	
	*str1 = '\0';
	return temp;
}
int main() {

	// printf("Hello, World!\n");
	char fruit[80] = "straw";	// R/O 영역에 한번만 잡힘
	printf("fuit 주소 : %p\n", "straw"); // 지금은 완전 동일하기 때문에 한 번만 잡힘
	// 이후로는 달라진다?
	printf("fuit 주소 : %p\n", fruit);
	printf("fruit: %s\n", fruit);
	//char fruit[80] = { 0 };
	// strcat(fruit, "berry");
	// printf("연결된 문자열 : %s\n", fruit);

	user_strcat(fruit, "berry");
	printf("연결된 문자열 : %s\n", fruit); 
	// char*형 쓰는 이유

	return 0;
}

/*
char* my_strcat(char* str1, char* str2) {
	char* str="\0";
	int cnt = 0;

	while (1) {
		str[cnt] = str1[cnt];
		if (str[cnt++] == '\0') break;
	}

	while (1) {
		int cnt2 = 0;
		str[cnt] = str1[cnt2++];
		if (str[cnt++] == '\0') break;
	}
	str[cnt] = '\0';

	return str;
}*/
