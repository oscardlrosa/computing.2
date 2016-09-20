/*
 * string.h
 *
 *  Created on: Mar 27, 2016
 *      Author: delarosa
 */

#ifndef STRING_H_
#define STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "status.h"

typedef void* STRING;
typedef struct string * String_Ptr;

STRING string_init_default(void);
STRING string_init_c_string(char* regCString);
Status string_destroy(STRING* hString);
char* string_print(STRING strObj);
int string_get_size(STRING strObj);
int string_get_capacity(STRING strObj);
Status string_extraction(STRING hString, FILE* inputFile);
Status string_insertion(STRING hString, FILE* inputFile);
Status string_push_back(STRING hString, char item);
Status string_pop_back(STRING hString);
Status string_concat(STRING hResult, STRING hAppend);
Boolean string_empty(STRING hString);
char* string_at(STRING hString, int index);
char* string_c_str(STRING hString);
int string_compare(STRING strObj1, STRING strObj2);


#endif /* STRING_H_ */
