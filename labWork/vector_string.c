/*
 * vector_string.c
 *
 *  Created on: Apr 18, 2016
 *      Author: delarosa
 */
#include "string.h"

struct vector_string
{
	int size;
	int capacity;
	STRING * data;
};

typedef struct vector_string Vector_String, * Vector_String_Ptr;


Vector_String_Ptr vector_string_init_default(void)
{
	Vector_String_Ptr pVector = (Vector_String_Ptr)malloc(sizeof(Vector_String));
	if(pVector != NULL)
	{
		pVector->size = 0;
		pVector->capacity = 1;
		pVector->data = (STRING)malloc(sizeof(STRING) * pVector->capacity);
		if(pVector->data == NULL)
		{
			free(pVector);
			pVector = NULL;
		}
	}
	return pVector;
}

void vector_string_destroy(Vector_String_Ptr * phVectorString)
{
	Vector_String_Ptr pphVectorString = (Vector_String_Ptr)*phVectorString;
	int i;

	if(pphVectorString != NULL)
	{
		for(i = 0; i < pphVectorString->capacity; i++)
		{
			if(pphVectorString->data[i] != NULL)
			{
				free(pphVectorString->data[i]);
			}
		}
		free(pphVectorString->data);
		free(pphVectorString);
		*phVectorString = NULL;
	}
}

Status vector_string_push_back(Vector_String_Ptr hVectorString, STRING hString)
{
	Vector_String_Ptr pVectorString = (Vector_String_Ptr)hVectorString;
	String_Ptr pString = (String_Ptr)hString;
	STRING* pTemp;
	int i;

	if(pVectorString->size >= pVectorString->capacity)
	{
		pTemp = (STRING*)malloc(sizeof(STRING) * pVectorString->capacity);
		if(pTemp == NULL)
			return FAILURE;

		for(i = 0; i < pVectorString->size; i++)
			pTemp[i] = pVectorString->data[i];

		for(; i < pVectorString->capacity; i++)
			pTemp[i] = NULL;

		pVectorString->capacity *= 2;

		free(pVectorString->data);
		pVectorString->data = pTemp;
	}

	pVectorString->data[pVectorString->size] = pString;

	if(pVectorString->data[pVectorString->size] == NULL)
		return FAILURE;

	pVectorString->size++;

	return SUCCESS;
}

int vector_string_get_size(Vector_String_Ptr hVectorString)
{
	Vector_String_Ptr pVectorString = (Vector_String_Ptr)hVectorString;

	return pVectorString->size;
}

int vector_string_get_capacity(Vector_String_Ptr hVectorString)
{
	Vector_String_Ptr pVectorString = (Vector_String_Ptr)hVectorString;

	return pVectorString->capacity;
}

Boolean vector_string_empty(Vector_String_Ptr hVectorString)
{
	Vector_String_Ptr pVectorString = (Vector_String_Ptr)hVectorString;

	if(pVectorString->size == 0)
		return TRUE;

	return FALSE;
}

STRING* vector_string_at(Vector_String_Ptr hVectorString, int index)
{
	Vector_String_Ptr pVectorString = (Vector_String_Ptr)hVectorString;

	if(index < 0 || index >= pVectorString->size)
		return NULL;

	return pVectorString->data[index];
}
