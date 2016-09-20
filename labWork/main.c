/*
 * main.c
 *
 *  Created on: Mar 27, 2016
 *      Author: delarosa
 */


#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "vector_string.h"
#include "array_vector_string.h"

//Simple.txt file includes the following sentence:
//The quick brown fox jumped over the lazy dogs.
//No spaces or newlines after that period

int main(int argc, char* argv[])
{
	Vector_String_Ptr hVectorStr = NULL;
	STRING hString = NULL;
	STRING hString2 = NULL;
	Status stat;
	Boolean empty;

	hVectorStr = vector_string_init_default();
	hString = string_init_c_string("My name is ");
	hString2 = string_init_c_string("Hova");

	printf("Size: %d  Capacity: %d\n", vector_string_get_size(hVectorStr), vector_string_get_capacity(hVectorStr));

	empty = vector_string_empty(hVectorStr);

	if(empty)
		printf("Vector string is empty.\n");
	else
		printf("Vector string is not empty.\n");

	stat = vector_string_push_back(hVectorStr, hString);
	if(stat)
		printf("Push back into vector string successful!!!.\n\n");
	else
		printf("Push back into vector string failed...\n\n");

	printf("Size: %d  Capacity: %d\n", vector_string_get_size(hVectorStr), vector_string_get_capacity(hVectorStr));

	stat = vector_string_push_back(hVectorStr, hString2);
	if(stat)
		printf("Push back into vector string successful!!!.\n\n");
	else
		printf("Push back into vector string failed...\n\n");

	printf("Size: %d  Capacity: %d\n", vector_string_get_size(hVectorStr), vector_string_get_capacity(hVectorStr));

	string_destroy(&hString);
	string_destroy(&hString2);
	vector_string_destroy(&hVectorStr);
//	STRING hString = NULL;
//	STRING result = NULL;
//	STRING read = NULL;
//	FILE* fp;
//
//	/**************************************************/
//	/***** Testing string_at and string_empty**********/
//	hString = string_init_c_string("Hello World!");
//	string_insertion(hString, stdout);
//	printf("\nString size: %d \n", string_get_size(hString));
//	printf("The string has letter: %c at index: 6\n", *string_at(hString,6));
//	printf("Is the string empty? %d\n ", string_empty(hString));
//	printf("\n");
//
//	/**************************************************/
//	/****Testing string_extraction ,string_insertion***/
//	/*********Testing string_concat********************/
//	result = string_init_default();
//	read = string_init_default();
//	fp = fopen("simple.txt", "r");
//	while(string_extraction(read,fp))
//	{
//		string_concat(result,read);
//		string_insertion(result,stdout);
//		printf("\n");
//	}
//
//	printf("\n");
//
//	/****************************************************/
//	/*********Testing empty and pop_back*****************/
//	while(string_empty(result) == FALSE)
//	{
//		string_pop_back(result);
//	}
//
//	printf("The string after popping all characters: \n");
//	printf("The string size: %d\n", string_get_size(result));
//	printf("Is the string empty? %d\n", (int)string_empty(result));
//
//	fclose(fp);
//	string_destroy(&result);
//	string_destroy(&read);
//	string_destroy(&hString);
//	return 0;
}
