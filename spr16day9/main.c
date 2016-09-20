/*
 * main.c
 *
 *  Created on: Apr 6, 2016
 *      Author: delarosa
 */


#include <stdio.h>
#include <stdlib.h>

void quick_sort(int givenArray[], int size);
void swap(int* firstValue, int* secondValue);

int main(int arg, char* argv[])
{
	int size, index, randomIndex;
	int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int reverseSortedArray[] = {10, 9, 8, 7 ,6, 5, 4, 3, 2, 1};
	int *randomlyGeneratedArray = (int*)malloc(sizeof(int)*10);

	for(randomIndex = 0; randomIndex < 10; randomIndex++)
		randomlyGeneratedArray[randomIndex] = rand() % 1000;

	size = sizeof(sortedArray)/sizeof(int);

	printf("Sorted Array:\n");
	for(index = 0; index < size; index++)
		printf("%d  ", sortedArray[index]);

	printf("\n***\n");
	quick_sort(sortedArray, size);

	for(index = 0; index < size; index++)
		printf("%d  ", sortedArray[index]);

	printf("\n\nReverse Sorted Array:\n");
	for(index = 0; index < size; index++)
		printf("%d  ", reverseSortedArray[index]);

	printf("\n***\n");
	quick_sort(reverseSortedArray,size);

	for(index = 0; index < size; index++)
		printf("%d  ", reverseSortedArray[index]);

	printf("\n\nRandomly Generated Array:\n");
	for(index = 0; index < size; index++)
		printf("%d  ", randomlyGeneratedArray[index]);

	printf("\n***\n");
	quick_sort(randomlyGeneratedArray,size);

	for(index = 0; index < size; index++)
		printf("%d  ", randomlyGeneratedArray[index]);

	return 0;
}

void quick_sort(int givenArray[], int size)
{

    int leftMark, rightMark, pivot;

    if (size < 2)
        return;

    pivot = givenArray[size / 2];

    for (leftMark = 0, rightMark = size - 1;; leftMark++, rightMark--) {

        while (givenArray[leftMark] < pivot)
            leftMark++;

        while (pivot < givenArray[rightMark])
            rightMark--;

        if (leftMark >= rightMark)
            break;

        swap(&givenArray[leftMark],&givenArray[rightMark]);
    }
    quick_sort(givenArray, leftMark);
    quick_sort(givenArray + leftMark, size - leftMark);
}

void swap(int* firstValue, int* secondValue)
{
	int temp;

	temp = *firstValue;
	*firstValue = *secondValue;
	*secondValue = temp;
}
