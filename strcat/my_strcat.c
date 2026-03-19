#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* my_strcat(char* str1, char* str2);

int main() {

	char fruit[80] = "straw";
	strcat(fruit, "berry");
	printf("연결된 문자열 : %s\n", fruit);

	char test[90] = "test";
	my_strcat(test, "berry");
	printf("연결된 문자열 : %s\n", fruit);

	return 0;
}

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
}
