#include "mystring.h"
#include <stdio.h>
#include <stdlib.h>

/*
 *   Implement the following functions: 
 * 
 *   You are NOT allowed to use any standard string functions such as 
 *   strlen, strcpy or strcmp or any other string function.
 */

/*
 *  mystrlen() calculates the length of the string s, 
 *  not including the terminating character '\0'.
 *  Returns: length of s.
 */
int mystrlen (const char *s) 
{
	int length = 0;			    //Initialize length to 0
	while(s[length] != '\0'){	//Iterate through string
		length++;			    //Increase length
	}
	return length;
}

/*
 *  mystrcpy()  copies the string pointed to by src (including the terminating 
 *  character '\0') to the array pointed to by dst.
 *  Returns: a  pointer to the destination string dst.
 */
char  *mystrcpy (char *dst, const char *src)
{
    int i = 0;
	while(src[i] != '\0'){
		dst[i] = src[i];
        ++i;
	}
	dst[i] = '\0';
	return dst;
}

/*
 * mystrcmp() compares two strings alphabetically
 * Returns: 
 * 	-1 if s1  < s2
 *  	0 if s1 == s2
 *  	1 if s1 > s2
 */
int mystrcmp(const char *s1, const char *s2)
{
	if(s1 < s2) return -1;
	else if(s1 == s2) return 0;
	else return 1;
}

/*
 * mystrdup() creates a duplicate of the string pointed to by s. 
 * The space for the new string is obtained using malloc.  
 * If the new string can not be created, a null pointer is returned.
 * Returns:  a pointer to a new string (the duplicate) 
 	     or null If the new string could not be created for 
	     any reason such as insufficient memory.
 */
char *mystrdup(const char *s1)
{
	char *s = malloc(sizeof(char));
	s = mystrcpy(s, s1);
	return s;
}

