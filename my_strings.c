/*******************************************************************************
*
* File Name         : my_strings.c
* Created By        : Alexandre DUPUY
* Creation Date     : August 31th, 2015
* Last Change       : September 12th, 2015 at 04:01:57 PM
* Last Changed By   : Alexandre DUPUY
* Purpose           :
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "my_strings.h"

size_t my_strlen(const char *str)
{
	size_t len = 0;
	
	while (str[len]) {
		len++;
	}
	
	return len;	
}

char *my_str_capitalize(const char *str)
{
	char *capitalized=(char*)malloc(sizeof(char)*my_strlen(str));
	
	for (int i = 0; i < (int) my_strlen(str); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') capitalized[i] = str[i] - ('a'-'A');	
	}
	
	return capitalized;
}

int my_strcmp (const char *str1, const char *str2)
{
	int lenMax = my_strlen(str1);
	int len2 = my_strlen(str2);
	
	if (lenMax < len2) lenMax = len2;
	for (int i = 0; i < lenMax; i++) {
		if (str1[i] > str2[i]) return(1);
		if (str1[i] < str2[i]) return(-1);
	}

	return(0);
}

char *my_strcat(const char *str1, const char *str2, int nbChars)
{
	size_t len1 = my_strlen(str1);
	int i;
	char *str= (char*)malloc(sizeof(char) * (len1 + nbChars));
	
	for (i = 0; str1[i]; i++) {
		str[i] = str1[i];
	}

	for (i = 0; i < nbChars; i++) {
		str[i + len1] = str2[i];
	}
	
	return(str);
}
