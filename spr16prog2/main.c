/**********************************************************************

Program: Ferry Loading
Author: Oscar De La Rosa
Time spent: 15h+

***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define CM_TO_M .01

void run_cases(int number_of_cases);
int get_length_and_side(QUEUE hLeft, QUEUE hRight);
void ferry_crossing(QUEUE hLeft, QUEUE hRight, int trip_counter, int length_of_ferry);
void test_ferry_capacity(QUEUE hList, int length_of_ferry);

int main(int argc, char* argv[])
{
	int number_of_cases;
	
	fscanf(stdin, "%d", &number_of_cases);
	
	run_cases(number_of_cases);
	
	return 0;
}

void run_cases(int number_of_cases)
{
	QUEUE hLeft = NULL;
	QUEUE hRight = NULL;
	int length_of_ferry;
	int trip_counter = 1;
	
	while(number_of_cases > 0)
	{	
		hLeft = queue_init_default();
		hRight = queue_init_default();
		
		if(hLeft == NULL || hRight == NULL)
		{
			printf("ERROR! Couldn't allocate space for the list!\n");
			exit(1);
		}
	
		length_of_ferry = get_length_and_side(hLeft, hRight);
		
		ferry_crossing(hLeft, hRight, trip_counter, length_of_ferry);
		
		queue_destroy(&hLeft);
		queue_destroy(&hRight);
		number_of_cases--;
		trip_counter++;
	}
	
	return;
}


int get_length_and_side(QUEUE hLeft, QUEUE hRight)
{
	char direction[10];
	int length_of_ferry, number_of_cars, length_of_car;
	Status code;

	fscanf(stdin, "%d %d", &length_of_ferry, &number_of_cars);
	
	while(number_of_cars > 0)
	{
		memset(direction, 0, 10);
		

		fscanf(stdin, "%d %s", &length_of_car, &direction[0]);
		
		if(strncmp(direction, "left", 4) == 0)
			code = queue_push_back(hLeft, length_of_car);
		

		if(strncmp(direction, "right", 5) == 0)
			code = queue_push_back(hRight, length_of_car);

		if(code == FAILURE)
		{
			printf("ERROR! Failed to push to the back of the list!\n");
			exit(1);
		}
	
		number_of_cars--;
	}

	return length_of_ferry;
}

void ferry_crossing(QUEUE hLeft, QUEUE hRight, int trip_counter, int length_of_ferry)
{
	int trips = 0;

	while( queue_size(hLeft) > 0 || queue_size(hRight) > 0)
	{
		if(queue_size(hLeft) != 0)
			test_ferry_capacity(hLeft, length_of_ferry);

		trips++;
		
		if(queue_size(hLeft) == 0 && queue_size(hRight) == 0)
			break;
		
		if(queue_size(hRight) != 0)
			test_ferry_capacity(hRight, length_of_ferry);

		trips++;
	}
	printf("%d\n", trips);
	
	return;
}

void test_ferry_capacity(QUEUE hQueue, int length_of_ferry)
{
	float ferry = 0;
	
	while(ferry <= length_of_ferry)
	{
		if(queue_size(hQueue) == 0)
			break;
			
		if( ( ( *(queue_front(hQueue)) * CM_TO_M ) + ferry ) > length_of_ferry )
			break;
		
		ferry += *(queue_front(hQueue)) * CM_TO_M;
		queue_pop_front(hQueue);
	} 
	return;
}
