#include "queue.h"

#include <stdlib.h>

typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

struct queue
{
	Node* head;
	Node* tail;
};
typedef struct queue Queue;

int find_size(Node* head);


QUEUE queue_init_default(void)
{
	Queue *temp;

	temp = (Queue*) malloc(sizeof(Queue));
	if(temp != NULL)
	{
		temp->head = NULL;
		temp->tail = NULL;
	}


	return (QUEUE) temp;
}

int queue_size(QUEUE hQueue)
{
	Queue *pQueue= (Queue*) hQueue;
	if(pQueue != NULL)
		return find_size(pQueue->head);

	return -1;
}

Status queue_push_back(QUEUE hQueue, int item)
{
	Queue *pQueue= (Queue*) hQueue;
	Node* temp;

	if(pQueue != NULL)
	{
		temp = (Node*) malloc(sizeof(Node));
		if(temp == NULL)
			return FAILURE;

		temp->data = item;
		temp->next = NULL;
		if(pQueue->head == NULL && pQueue->tail == NULL)
		{
			pQueue->head = temp;
			pQueue->tail = temp;
		}
		else
		{
			pQueue->tail->next = temp;
			pQueue->tail = temp;
		}
		return SUCCESS;
	}
	else
		return FAILURE;
}

void queue_destroy(QUEUE* pQueue)
{
	Queue *ppQueue = (Queue*) *pQueue;

	Node* temp;
	if(ppQueue != NULL)
	{
		temp = ppQueue->head;

		while(temp != NULL)
		{
			ppQueue->head = ppQueue->head->next;
			free(temp);
			temp = ppQueue->head;
		}	
		free(ppQueue);
		*pQueue = NULL;
	}
	

	return;
}

int find_size(Node* head)
{
	Node* temp = head;
	int size = 0;

	while(temp != NULL)
	{
		size++;
		temp = temp->next;
	}

	return size;
}

Status queue_pop_front(QUEUE hQueue)
{
	Queue *pQueue = (Queue*) hQueue;

	Node* temp;

	if(pQueue != NULL)
	{
		if(pQueue->head !=NULL)
		{
			temp = pQueue->head;
			pQueue->head = pQueue->head->next;
			free(temp);
			if(pQueue->head == NULL)
			{
				pQueue->tail = NULL;
			}
			return SUCCESS;
		}
	}
	return FAILURE;

}

int* queue_front(QUEUE hQueue)
{
	Queue *pQueue = (Queue*) hQueue;

	if(pQueue != NULL)
	{
		if(pQueue->head != NULL)
		{
			return &(pQueue->head->data);
		}
	}
	return NULL;

}
