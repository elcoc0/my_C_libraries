/*******************************************************************************
*
* File Name         : my_strings.c
* Created By        : Alexandre DUPUY
* Creation Date     : August 31th, 2015
* Last Change       : September 23th, 2015 at 09:23:39 PM
* Last Changed By   : Alexandre DUPUY
* Purpose           : Own implementation of stdio library 
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <math.h>
#include "my_stdio.h"
#include "my_strings.h"

char char_int[10] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

int my_putchar(int i)
{
	write(1, &i, sizeof(int));
	return(0);
}

int my_put_nbr(int n)
{
	return(my_put_nbr_base(n, 10, 0));
}
int my_put_double(double d)
{
	return(my_put_double_base(d, 10, 0));
}

int my_put_unsigned_int(unsigned int ui)
{
	return(my_put_unsigned_int_base(ui, 10, 0));
}

int my_put_long_int(long int li)
{
	return(my_put_long_int_base(li, 10, 0));
}

int my_put_nbr_base(int n, int base, int capitalized)
{
	if (n < 0) {
		my_putchar('-');
		if (n != -2147483648) {
			my_put_nbr_base(-n,base, capitalized);
		
		} else {
			my_puts("2147483648");
		}
	
	} else if (n >= base) {
		my_put_nbr_base(n/base, base, capitalized);
		my_put_nbr_base(n%base, base, capitalized);
	
	} else if (n <= 9){
		my_putchar(n + '0');
	
	} else {
		my_putchar((capitalized == 1 ? 'A' : 'a') + n - 10);
	}

	return(0);
}	

int my_put_double_base(double d, int base, int capitalized)
{
	if (d < 0) {
		my_putchar('-');
		my_put_double_base(-d,base, capitalized);
	
	} else if (d >= base) {
		my_put_double_base(trunc(d/(double)base), base, capitalized);
		my_put_double_base(fmod(d,(double)base), base, capitalized);
	
	} else if (d <= 9) {
		my_putchar(d + '0');
	
	} else {
		my_putchar((capitalized == 1 ? 'A' : 'a') + d - 10);
	}
	
	return(0);
}

int my_put_unsigned_int_base(unsigned int ui, int base, int capitalized)
{
	if(ui >= (unsigned int) base) {
		my_put_unsigned_int_base(ui/base, base, capitalized);
		my_put_unsigned_int_base(ui%base, base, capitalized);
	
	} else if (ui <= 9) {
		my_putchar(ui + '0');
	
	} else {
		my_putchar((capitalized == 1 ? 'A' : 'a') + ui - 10);
	}
	
	return(0);
}

int my_put_long_int_base(long int li, int base, int capitalized)
{
	if (li < 0){
		my_putchar('-');
		my_put_long_int_base(li, base, capitalized);
	
	} else if (li >= base) {
		my_put_long_int_base(li/base, base, capitalized);
		my_put_long_int_base(li%base, base, capitalized);
	
	} else if (li <= 9){
		my_putchar(li + '0');
	
	} else {
		my_putchar((capitalized == 1 ? 'A' : 'a') + li - 10);
	}
	
	return(0);
}

int my_puts(const char *str)
{
	for (int i = 0; str[i]; i++) {
		my_putchar(str[i]);
	}
	
	return(0);
}

int is_in_char_array(const char c, const char *array)
{
	for (int i = 0; array[i]; i++) {
		if (c == array[i]) return(i);
	}

	return(-1);
}

int get_length_digits(int n)
{
	return (n == 0) ?  1 : floor(log10(abs(n))) + 1;
}

int my_printf(const char *format, ...)
{
	va_list args;
	int number_value;
	int hashtag_flag = 0;
	int space_flag = -1;
	int sign_flag = 0;
	int j;
	unsigned int unsigned_value;
	double double_value;
	long int ptr_value;
	char char_value;
	char *string_value;
	va_start(args, format);

	for (int i = 0; format[i]; i++) {
		if (format[i] != '%') {
			my_putchar(format[i]);
		
		} else {
		
			if (format[i+1] == '#') {
				hashtag_flag = 1;
				i++;
			}
			
			if ((space_flag = is_in_char_array(format[i+1], char_int)) != -1) {
				i++;
			}
			
			if (format[i+1] == ' ') {
				my_putchar(' ');
				i++;
			}
			
			if (format[i+1] == '+') {
				sign_flag = 1;
				i++;
			
			} else if (format[i+1] == '-') {
				sign_flag = 2;
				i++;
			}
			
			if (format[i+1] == 'd' || format[i+1] == 'i') {
				number_value = va_arg(args, int);
				
				if (space_flag != -1) {
					for (j = 0; j < (space_flag - get_length_digits(number_value)); j++) {
						my_putchar(' ');
					}
				}
				
				if (sign_flag == 1 && number_value > 0) {
					my_putchar('+');
				}
				
				my_put_nbr(number_value);
			
			} else if (format[i+1] == 'u') {
				unsigned_value = va_arg(args, unsigned int);
				my_put_unsigned_int(unsigned_value);
			
			} else if (format[i+1] == 'b') {
				number_value = va_arg(args, int);
				my_put_nbr_base(number_value, 2, 0);
			
			} else if (format[i+1] == 'o') {
				if (hashtag_flag == 1) my_puts("0");
				number_value = va_arg(args, int);
				my_put_nbr_base(number_value, 8, 0);
			
			} else if (format[i+1] == 'c') {
				char_value = va_arg(args, int);
				my_putchar(char_value);
			
			} else if (format[i+1] == 's' || format[i+1] == 'S') {
				string_value = va_arg(args, char*);
				my_puts(string_value);
			
			} else if (format[i+1] == 'x') {
				if (hashtag_flag == 1) my_puts("0x");
				ptr_value = va_arg(args, long int);
				my_put_long_int_base(ptr_value, 16, 0);
			
			} else if (format[i+1] == 'p') {
				my_puts("0x");
				ptr_value = va_arg(args, long int);
				my_put_long_int_base(ptr_value, 16, 0);
			
			} else if (format[i+1] == 'X') {
				if(hashtag_flag == 1) my_puts("0X");
				ptr_value = va_arg(args, long int);
				my_put_long_int_base(ptr_value, 16, 1);
			
			} else if (format[i+1] == 'f') {
				double_value = va_arg(args, double);
				my_put_double(double_value);
			
			} else if (format[i+1] == '%') {
				my_putchar('%');
			
			} else {
				my_putchar(format[i]);
				my_putchar(format[i + 1]);
			}
			
			i++;	
			hashtag_flag = 0;
			space_flag = -1;
			sign_flag = 0;
		}
	}
	va_end(args);
	
	return(0);
}