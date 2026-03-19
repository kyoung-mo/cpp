#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* user_strcat(char* str1, const char* str2)
{
	char* temp = str1;
	while (*str1 != '\0') 
		str1++;
	
	while (*str2 != '\0'){
		*(str2++) = *(str1++);
	}
	
	*str1 = '\0';
	return temp;
}
int main() {

	char fruit[80] = "straw";	// R/O 영역에 한번만 잡힘
	printf("fuit 주소 : %p\n", "straw"); // 지금은 완전 동일하기 때문에 한 번만 잡힘
	printf("fuit 주소 : %p\n", fruit);
	printf("fruit: %s\n", fruit);

	user_strcat(fruit, "berry");
	printf("연결된 문자열 : %s\n", fruit); 

	return 0;
}

