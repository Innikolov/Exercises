#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <string.h>

// Work in progress! 

int strend(char* str1, char* str2);

int main() {

	char* str1 = "hello there, how are you?";
	char* str2 = " how are you oskj?";

	int result = strend(str1, str2);

	printf("%d", result);
}


int strend(char* str1, char* str2) {

	int s1;
	int s2;
	int diff = strlen(str1) - strlen(str2);

	for (s1 = strlen(str1); s1 > diff && s1 - diff >= 0; s1--){
		s2 = s1 - diff;

		if (strcmp(str1[s1], str2[s2]) == 0){
			return 1;
		}
		else return 0;
	}

} 