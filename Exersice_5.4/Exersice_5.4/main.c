#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <string.h>

// Work in progress! 

int strend(char* s, char* t);

int main() {

	char* str1 = "hello there, how are you?";
	char* str2 = " how are you?";

	int result = strend(str1, str2);

	printf("%d", result);
}


	int strend(char* s, char* t)
	{
		if (strlen(s) < strlen(t)) return 0;

		//s is an address, pointing to the beginning of string *s. Adding integers to s resolves 
		// in changing the starting point of the string.
		return !strcmp(s + strlen(s) - strlen(t), t);
	}
