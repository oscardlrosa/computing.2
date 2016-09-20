/*
 * string.c
 *
 *     Program: string.c
 *        Date: Mar 30, 2016
 *      Author: Oscar De La Rosa
 *     Purpose: Implementation of string.h
 */


#include "string.h"

typedef struct string
{
        char* char_arr;
        int capacity;
        int size;
} String;

STRING string_init_default(void)
{
	String* pString;
	pString = (String*)malloc(sizeof(String));
	if(pString != NULL)
	{
		pString->size = 0;
		pString->capacity = 7;
		pString->char_arr = malloc(sizeof(char) * pString->capacity);
		if(pString->char_arr == NULL)
		{
			free(pString);
			pString = NULL;
			exit(1);
		}
	}

	return pString;
}

STRING string_init_c_string(char* c_str)
{
	String* pString;
	int len = 0, i = 0;
	while(c_str[len] != '\0') len++;

	pString = (String*)malloc(sizeof(String));
	if(pString != NULL)
	{
		pString->size = len;
		pString->capacity = len + 1;
		pString->char_arr = malloc(sizeof(char) * pString->capacity);
		if(pString->char_arr == NULL)
		{
			free(pString);
			pString = NULL;
			exit(1);
		}
		while(c_str[i] != '\0')
		{
			pString->char_arr[i] = c_str[i];
			i++;
		}
		pString->char_arr[i] = '\0';
	}

	return pString;
}

//PRE: hString is the handle to a valid STRING object.
//POST: Returns the address of the character located at the given index if the index is in bounds but otherwise returns NULL. This address is not usable as a c-string since the data is not NULL terminated and is intended to just provide access to the element at that index.
char* string_at(STRING hString, int index)
{
	String* pString = (String*) hString;
	char* ret_val;

	if(pString->size < index)
	{
		printf("Out of bounds.\n");
		ret_val = NULL;
	}
	else
	{
		ret_val = &(pString->char_arr[index]);
	}

	return ret_val;
}

//PRE: hString is the handle to a valid STRING object.
//POST: Returns the address of the first element of the string object for use as a c-string. The resulting c-string is guaranteed to be NULL terminated and the memory is still maintained by the string object though the NULL is not actually counted as part of the string (in size).
char* string_c_str(STRING hString)
{
	String* pString = (String*) hString;
	char* ret_val;
	int i = 0;


	if(pString->size == 0)
	{
		ret_val = NULL;
	}
	else
	{
		while(pString->size < i && (pString->char_arr[i] != '\0' || pString->char_arr[i] != ' ' || pString->char_arr[i] != EOF))
		{
			i++;
		}

		pString->char_arr[i] = '\0';
		ret_val = &(pString->char_arr[0]);
	}

	return ret_val;
}


int string_compare(STRING hString1, STRING hString2)
{
	int result, i = 0;

	String* phString1 = (String*) hString1;
	String* phString2 = (String*) hString2;

	while(phString1->char_arr[i] == phString2->char_arr[i])
	{
		result = 0;
		if(phString1->char_arr[i] == '\0' || phString2->char_arr[i] == '\0')
			break;

		i++;
	}

	if(phString1->char_arr[i] && phString2->char_arr[i])
		return result;
	else if(phString1->char_arr[i] < phString2->char_arr[i])
		result = -1;
	else if(phString1->char_arr[i] > phString2->char_arr[i])
		result = 1;

	return result;
}

int string_get_size(STRING hString)
{
	String* pString;
	pString = (String*) hString;
	return pString->size;
}

int string_get_capacity(STRING hString)
{
	String* pString;
	pString = (String*) hString;
	return pString->capacity;
}

Status string_extraction(STRING hString, FILE* inputFile)
{
	char c;
	int i = 0, fscanfReturn;
	Status stat;
	String* pString;
	pString = (String*) hString;

	if(inputFile == NULL)
	{
		printf("File could not be found.\n");
		stat = FAILURE;
	}
	else
	{
		while(inputFile != NULL)
		{
			fscanfReturn = fscanf(inputFile, "%c", &c);
			if(fscanfReturn == EOF)
			{
				stat = FAILURE;
				break;
			}
			else
			{
				// If first char read is a space, trap it here until is not
				while(isspace(c))
				{
					c = fgetc(inputFile);
				}
				pString->size++;
				pString->char_arr[i] = c;
				i++;
				c = fgetc(inputFile);
				while(c != -1 && !isspace(c))
				{
					pString->size++;

					if(pString->size == pString->capacity)
					{
						char* new_char_arr;
						int j = 0;
						new_char_arr = (char*)malloc(pString->capacity * 2);

						while(pString->char_arr[j] != '\0')
						{
							new_char_arr[j] = pString->char_arr[j];
							j++;
						}
						new_char_arr[j] = '\0';

						free(pString->char_arr);
						pString->char_arr = new_char_arr;
						pString->capacity *= 2;
					}

					pString->char_arr[i] = c;
					c = fgetc(inputFile);
					i++;
				}
				if(isspace(c))
				{
					ungetc(c, inputFile);
					stat = SUCCESS;
					pString->char_arr[i] = ' ';
					pString->char_arr[++i] = '\0';
					break;
				}
			}
		}
	}
	return stat;
}

Status string_insertion(STRING hString, FILE* inputFile)
{
	int i = 0, c;
	String* pString;
	pString = (String*) hString;

	c = fputc(pString->char_arr[i], inputFile);
	if(c == EOF)
		return FAILURE;

	while(c != '\0')
	{
		i++;
		c = fputc(pString->char_arr[i], inputFile);
	}
	fputc('\0', inputFile);

	return SUCCESS;
}

//PRE:	hString is a handle to a valid string object,item is a character to add to the end of the string
//POST:	return SUCCESS if the item is successfully added to the end of the string. The end of the string refers to the current size of the string. If the string reached its maximum capacity, i.e., size == capacity, then the string needed to be resized to be able to add the new item. Resize the string by doubling its capacity Return FAILURE if the string could not be resized
Status string_push_back(STRING hString, char item)
{
	Status stat = FAILURE;
	String* pString;
	pString = (String*) hString;
	char* pTemp;
	int i;

	if(pString->size >= pString->capacity)
	{
		pTemp = (char*)malloc(sizeof(char)*pString->capacity * 2);
		if(pTemp == NULL)
			return stat;
		else
		{
			for(i = 0; i < pString->size; i++)
			{
				pTemp[i] = pString->char_arr[i];
			}
			free(pString->char_arr);
			pString->char_arr = pTemp;
			pString->capacity *= 2;
			pString->char_arr[pString->size] = item;
			stat = SUCCESS;
		}
	}
	else
	{
		pString->char_arr[pString->size] = item;
		stat = SUCCESS;
	}

	pString->size++;

	return stat;
}

//PRE:	hString is a handle to a valid string object
//POST:	Removes the last character in the string. Returns SUCCESS if the last character was successfully removed and FAILURE if the string was empty
Status string_pop_back(STRING hString)
{
	Status stat = FAILURE;
	String* pString = (String*) hString;
	int i;

	if(pString->char_arr == NULL)
		return stat;

	for(i = 0; i < pString->size; i++)
	{
		pString->char_arr[pString->size - 1] = '\0';
		stat = SUCCESS;
	}
	pString->size--;

	return stat;
}

//PRE: hResult and hAppend are handles to valid String objects.
//POST: hResult is the handle of a string that contains the original
// hResult object followed by the hAppend object concatenated together. This
// function should guarantee no change to the hAppend object and return
// SUCCESS if they operation is successful and FAILURE if the hResult object
// is unable to accomodate the characters in the hAppend string perhaps
// because of a failed resize operation. On FAILURE, no change to either
// string should be made.
Status string_concat(STRING hResult, STRING hAppend)
{
	String* pResult = (String*) hResult;
	String* pAppend = (String*) hAppend;
	char* pTemp;

	Status stat = FAILURE;
	int i = 0, j = 0, k = 0;

	while(pAppend->char_arr[i] != '\0')
	{
		if(pResult->capacity <= pAppend->size)
		{
			pTemp = (char*)malloc(sizeof(char)*pResult->capacity * 2);
			if(pTemp == NULL)
				return stat;
			else
			{
				for(; k < pResult->size; k++)
				{
					pTemp[k] = pResult->char_arr[k];
				}
				free(pResult->char_arr);
				pResult->char_arr = pTemp;
				pResult->capacity *= 2;
			}
		}

		while(pResult->char_arr[j])
			j++;

		while(pAppend->char_arr[i])
		{
			pResult->char_arr[j] = pAppend->char_arr[i];
			pResult->size++;
			i++;
			j++;
		}
		pResult->char_arr[j] = '\0';
		stat = SUCCESS;
	}

	return stat;

}

//PRE: hMy_string are handles to a valid string object and inputFile is a file pointer
//POST: get the characters from a line until new space
Status get_line(STRING hString, FILE* inputFile)
{
	char c;
	char* pTemp;
	int index;

	String* pString = (String*)hString;

	if(pString->size > 0)
	{
		free(pString->char_arr);
		pString->size = 0;
		pString->capacity = 20;

		pString->char_arr = (char*)malloc(sizeof(pString->capacity));
		if(pString->char_arr == NULL)
		{
			free(pString);
			pString = NULL;
			exit(1);
		}
	}

	do
	{
		c = fgetc(inputFile);
		if(c == EOF)
			break;
		pString->char_arr[pString->size] = c;
		pString->size++;

		if(pString->size >= pString->capacity)
		{
			pTemp = (char*)malloc(sizeof(char) * pString->capacity * 2);
			if(pTemp != NULL)
			{
				for(index = 0; index < pString->size; index++)
					pTemp[index] = pString->char_arr[index];

				free(pString->char_arr);
				pString->char_arr = pTemp;
				pString->capacity *= 2;
			}
		}

		if(c == '\n' || c == EOF)
			return SUCCESS;

	} while(c != '\n' || c != EOF);

	return FAILURE;
}

Boolean is_palindrome(STRING hString)
{
	char* pTemp;
	int front, back, size, index = 0;
	String* pString = (String*) hString;

	pTemp = (char*)malloc(sizeof(char) * pString->capacity);
	if(pTemp != NULL)
	{
		for(front = 0, back = 0; front < pString->size; front++, back++)
		{
			if(isalpha(pString->char_arr[front]))
			{
				if(isupper(pString->char_arr[front]))
				{
					pTemp[back] = tolower(pString->char_arr[front]);
				}
				else
					pTemp[back] = pString->char_arr[front];
			}
			else
				back--;
		}
	}

	size = back;
	for(index = 0; index < size; index++)
	{
		if(pTemp[index] != pTemp[size - 1])
		{
			printf("No\n");
			return FALSE;
		}
		size--;
	}
	printf("Yes\n");
	return TRUE;
}


//PRE: hString is the handle to a valid String object.
//POST: Returns an enumerated type with value TRUE if the string is empty and FALSE otherwise.
Boolean string_empty(STRING hString)
{
	Boolean stat;
	String* pString = (String*) hString;

	if(pString->size <= 0)
		stat = TRUE;
	else
		stat = FALSE;

	return stat;
}
//PRE: hString is the handle to a valid STRING object.
//POST: Destroys the char_arr and memory footprint of object
Status string_destroy(STRING* hString)
{
	Status stat = FAILURE;
	String* pPString = (String*) *hString;

	if(pPString != NULL)
	{
		free(pPString->char_arr);
		free(pPString);
		stat = SUCCESS;
	}
	pPString = NULL;

	return stat;
}

