/*
 * string.c
 *
 *     Program: Palindrome Program
 *        Date: Mar 30, 2016
 *      Author: Oscar De La Rosa
 *     Purpose: Display 'Yay' or 'Nay' if the read string is  a palindrome
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(int argc, char* argv[])
{
	STRING hMy_string = NULL;
	char c;


	hMy_string = string_init_default();

	c = fgetc(stdin);
	while(c != EOF)
	{
		ungetc(c, stdin);
		get_line(hMy_string, stdin);
		is_palindrome(hMy_string);
		c = fgetc(stdin);
	}

	string_destroy(&hMy_string);

	return 0;
}
