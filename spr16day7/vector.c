#include <stdlib.h>
#include "vector.h"

struct vector
{
	int size;
	int capacity;
	int* data;
};
typedef struct vector Vector;

VECTOR vector_init_default(void)
{
	Vector *temp = NULL;

	temp = (Vector*)malloc(sizeof(Vector));
	if(temp != NULL)
	{
		temp->size = 0;
		temp->capacity = 1;
		temp->data = (int*) malloc(sizeof(int)*temp->capacity);
		if(temp->data == NULL)
		{
			free(temp);
			temp = NULL;
		}
	}

	return (VECTOR) temp;
}

void vector_destroy(VECTOR* pVECTOR)
{
	Vector *temp = (Vector*)(*pVECTOR);
	if(temp != NULL)
	{
		free(temp->data);
		free(temp);
		*pVECTOR = NULL;
	}
}

Status vector_push_back(VECTOR hVector, int item)
{
	Vector *pVector = (Vector*)(hVector);
	int *temp;
	int i;

	if(pVector != NULL)
	{
		if(pVector->size >= pVector->capacity)
		{
			pVector->capacity *= 2;
			temp = (int*)malloc(sizeof(int)*pVector->capacity);
			if(temp != NULL)
			{			
				for(i = 0; i < pVector->size; i++)
				{
					temp[i] = pVector->data[i];
				}
				free(pVector->data);
				pVector->data = temp;
			}
			else
			{
				pVector->capacity /= 2;
				return FAILURE;
			}

		}
		pVector->data[pVector->size] = item;
		pVector->size++;
		return SUCCESS;
	}

	return FAILURE;	
}



int vector_size(VECTOR hVector)
{
	Vector* pVector = (Vector*) hVector;

	if(pVector != NULL)
	{
		return pVector->size;
	}
	else
	{
		return -1;
	}

}

int vector_capacity(VECTOR hVector)
{
	Vector* pVector = (Vector*) hVector;

	if(pVector != NULL)
	{
		return pVector->capacity;
	}
	else
	{
		return -1;
	}
}

int* vector_at(VECTOR hVector, int index)
{
	Vector* pVector = (Vector*) hVector;

	if(pVector != NULL)
	{
		if(index < pVector->size && index >= 0 )
		{
			return &(pVector->data[index]);
		}
	}

	return NULL;
}
