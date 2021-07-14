/* 

	Write new versions of functions strncpy, strncat and strncmp,
	that work with first n symbols of the strings. Example: strncat(s,t,n).

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


//adds n symbols from string t to the end of string s.
void strn_cat(char s[], char t[], size_t n);


//copies n symbols from string s to string t (replaces).
void strn_cpy(char* s, char* t, size_t* n);


//compares first n symbols of s and t, returns 1 if all n symbols match, 0 if they dont.
int strn_cmp(char s[], char t[], size_t n);


int main()
{
	char str1[100] = "Hi there! ";
	char str2[] = "How are you? It's a lovelly day!";
	char str3[100] = "abcdeg";
	char str4[100] = "abcgreafhad";

	printf("strings match: %d\n", strn_cmp(str3, str4, 3));

	strn_cat(str1, str2, 12);
	printf("%s ", str1);

	strn_cpy(str1, str3, 10);
	printf("\n%s ", str3);


}



int strn_cmp(char s[], char t[], size_t n) 
{
	unsigned int i = 0;
	while (n--)
	{
		if (t[i] != s[i]) 
		{
			return 0;
		}
		i++;
	}

	return 1;
}


void strn_cat(char s[], char t[], size_t n)
{
	int size = strlen(s);
	unsigned int i = 0;

	while (i < n && t[i] != '\0')
	{	
		s[size + i] = t[i];
		i++;
	}
	s[size + i] = '\0';
}


void strn_cpy(char s[], char t[], size_t n) {

	unsigned int i = 0;
	while (n--)
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
}
