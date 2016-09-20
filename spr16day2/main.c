/*
 * main.c
 *
 *  Created on: Jan 25, 2016
 *      Author: Oscar De La Rosa
 *      Effort: 20min
 *     Purpose: Write a main program that declares an unsigned integer named x and initializes it with the value of 1. Write a forloop
				that prints out an iteration number starting from zero, a colon, and the value of x on a
				single line. Your loop should then use the left shift operator to shift the value of x over by
				one bit to the left and then save the new value in x. Allow the loop to run until the number x
				is equivalent to zero
 */

#include<stdio.h>

int main(int argc, char* argv[])
{
	int x = 1, i = 0;

	for( ; x != 0; i++ )	// Run until x == 0
	{
		printf("%d:\t%u\n", i, x);
		x <<= 1;	// Move to the left bit and assign it to x
	}


	return 0;
}
