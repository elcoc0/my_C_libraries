/*******************************************************************************
*
* File Name         : my_stdio.h
* Created By        : Alexandre DUPUY
* Creation Date     : August 31th, 2015
* Last Change       : September 12th, 2015 at 02:58:20 PM
* Last Changed By   : Alexandre DUPUY
* Purpose           : Own impkementation of stdio library
*
*******************************************************************************/

#ifndef _MY_HEADER_
#define _MY_HEADER_

int my_putchar(int c);
int my_put_nbr(int n);
int my_put_double(double d);
int my_put_unsigned_int(unsigned int ui);
int my_put_long_int(long int li);
int my_put_nbr_base(int n, int base, int capitalized);
int my_put_double_base(double d, int base, int capitalized);
int my_put_unsigned_int_base(unsigned int ui, int base, int capitalized);
int my_put_long_int_base(long int li, int base, int capitalized);
int my_puts(const char *str);
int is_in_char_array(const char c, const char *array);
int get_length_digits(int n);
int my_printf(const char *format, ...);

#endif
