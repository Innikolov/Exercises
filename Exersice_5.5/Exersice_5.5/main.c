/* 

	Write new versions of functions strncpy, strncat and strncmp,
	that work with first n symbols of the strings. Example: strncat(s,t,n).

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


//adds n symbols from string t to the end of string s.
void strn_cat(char s[], char t[], size_t n);

int main()
{
	char str1[100] = "Hi there! ";
	char str2[] = "How are you? It's a lovelly day!";
	strn_cat(str1, str2, 12);

	printf("%s ", str1);
}


void strn_cat(char s[], char t[], size_t n)
{
	char* ptr = s;
	int size = strlen(s);
	unsigned int i = 0;

	while (i < n && t[i] != '\0')
	{	
		s[size + i] = t[i];
		i++;
	}
	s[size + i] = '\0';
}