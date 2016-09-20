#include <stdlib.h>
#include "stack.h"

struct stack
{
	int size;
	int capacity;
	char* data;
};
typedef struct stack Stack;

STACK stack_init_default(void)
{
	Stack *temp = NULL;

	temp = (Stack*)malloc(sizeof(Stack));
	if(temp != NULL)
	{
		temp->size = 0;
		temp->capacity = 1;
		temp->data = (char*) malloc(sizeof(char)*temp->capacity);
		if(temp->data == NULL)
		{
			free(temp);
			temp = NULL;
		}
	}

	return (STACK) temp;
}

void stack_destroy(STACK* pSTACK)
{
	Stack *temp = (Stack*)(*pSTACK);
	if(temp != NULL)
	{
		free(temp->data);
		free(temp);
		*pSTACK = NULL;
	}
}

Status stack_push_back(STACK hStack, char item)
{
	Stack *pStack = (Stack*)(hStack);
	char *temp;
	int i;

	if(pStack != NULL)
	{
		if(pStack->size >= pStack->capacity)
		{
			pStack->capacity *= 2;
			temp = (char*)malloc(sizeof(char)*pStack->capacity);
			if(temp != NULL)
			{			
				for(i = 0; i < pStack->size; i++)
					temp[i] = pStack->data[i];

				free(pStack->data);
				pStack->data = temp;
			}
			else
			{
				pStack->capacity /= 2;
				return FAILURE;
			}

		}
		pStack->data[pStack->size] = item;
		pStack->size++;
		return SUCCESS;
	}

	return FAILURE;	
}

Status stack_pop_back(STACK hStack)
{
	Stack *pStack = (Stack*)(hStack);
	int size;
	
	if(pStack == NULL)
	{
		return FAILURE;
	}
	
	size = pStack->size;
	
	if(size > 0)
	{
		pStack->data[size] = 0;
		pStack->size--;
	}
	else
		return FAILURE;
	
	return SUCCESS;

}

int stack_size(STACK hStack)
{
	Stack* pStack = (Stack*) hStack;

	if(pStack != NULL)
	{
		return pStack->size;
	}
	else
	{
		return -1;
	}

}

int stack_capacity(STACK hStack)
{
	Stack* pStack = (Stack*) hStack;

	if(pStack != NULL)
	{
		return pStack->capacity;
	}
	else
	{
		return -1;
	}
}

char* stack_at(STACK hStack, int index)
{
	Stack* pStack = (Stack*) hStack;

	if(pStack != NULL)
	{
		if(index < pStack->size && index >= 0 )
		{
			return &(pStack->data[index]);
		}
	}

	return NULL;
}
