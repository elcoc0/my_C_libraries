/*******************************************************************************
*
* File Name         : my_strings.h
* Created By        : Alexandre DUPUY
* Creation Date     : August 31th, 2015
* Last Change       : September 23th, 2015 at 09:24:35 PM
* Last Changed By   : Alexandre DUPUY
* Purpose           : Own implementation of strings library
*
*******************************************************************************/

#ifndef _MY_HEADER_
#define _MY_HEADER_

size_t my_strlen(const char *str);
char *my_str_capitalize(const char *str);
int my_strcmp (const char *str1, const char *str2);
char *my_strcat(const char *str1, const char *str2, int nbChars);

#endif
