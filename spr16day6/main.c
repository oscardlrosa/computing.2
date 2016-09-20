/*
 * main.c
 *
 *  Created on: Feb 21, 2016
 *      Author: Oscar De La Rosa
 *     Program: Reverse-me a Linked List
 *     Purpose: The purpose of this program is to reverse, in place, a given linked list
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

typedef struct node
{
	int data;
	Node* next;
}Node;

//declare your function here.
Node* linked_list_reverse(Node* head);
void linked_list_print(Node* head);

int main(int argc, char* argv[])
{
	Node* head = NULL;
	Node* temp;
	int i;


	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

	//print the list.
	linked_list_print(head);

	//reverse the list
	head = linked_list_reverse(head);
	printf("***\n");

	//print the list, now REVERSE!!!.
	linked_list_print(head);

	return 0;
}

// PRE: Take head node of linked list
// POST: Reverse taken linked list, in-place
Node* linked_list_reverse(Node* head)
{
	Node* temp;
	Node* prev = NULL;

	while (head != NULL)
	{
		temp = head->next;	// Set temp to point to the next item on the list
		head->next = prev;	// Set current item to point to the previous item
		prev = head;		// Previous item is now where we are in the list
		head = temp;		// Current item points to the next item on the list
	}
	return prev;
}

// PRE: Take head node of linked list
// POST: Print linked list
void linked_list_print(Node* head)
{
	Node* temp = head;

	if (temp == NULL)
	{
		printf("Nothing to print.\nList is empty.\n");
		exit(1);
	}

	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
