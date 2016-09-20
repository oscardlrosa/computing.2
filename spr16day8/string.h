/*
 * string.c
 *
 *     Program: Palindrome Program
 *        Date: Mar 30, 2016
 *      Author: Oscar De La Rosa
 *     Purpose: Function declarations for string opaque object
 */




#ifndef STRING_H_
#define STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "status.h"

typedef void* STRING;

STRING string_init_default(void);
STRING string_init_c_string(char* regCString);
char* string_at(STRING hString, int index);
char* string_c_str(STRING hString);
int string_get_size(STRING hString);
int string_get_capacity(STRING hString);
int string_compare(STRING hString1, STRING hString2);
Boolean is_palindrome(STRING hString);
Boolean string_empty(STRING hString);
Status string_extraction(STRING hString, FILE* inputFile);
Status string_insertion(STRING hString, FILE* inputFile);
Status string_push_back(STRING hString, char item);
Status string_pop_back(STRING hString);
Status string_concat(STRING hResult, STRING hAppend);
Status get_line(STRING hString, FILE* inputFile);
Status string_destroy(STRING* hString);

#endif /* STRING_H_ */
