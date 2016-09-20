/*
 * main.c
 *
 *  Created on: Feb 3, 2016
 *      Author: Oscar De La Rosa
 *     Purpose: Implement bitwise operation on an array of a given size
 */
#include <stdio.h>
#include <stdlib.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_32_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char* argv[])
{
	unsigned int flag_holder[5] = { 0 };	// Set the first integer to zero and all other to zero by default

	set_flag(flag_holder, 3);
	set_flag(flag_holder, 16);
	set_flag(flag_holder, 31);
	set_flag(flag_holder, 87);

	display_flags(flag_holder, 5);
	printf("\n\n");

	unset_flag(flag_holder, 31);
	unset_flag(flag_holder, 3);
	set_flag(flag_holder, 99);
	set_flag(flag_holder, 100);

	display_flags(flag_holder, 5);
	return 0;
}

//PRECON: Take int array and int for position
//POSTCON: Set flag_positition bit to 1
void set_flag(unsigned int flag_holder[], int flag_position)
{
	int bit_to_set = flag_position;	// This is the position in the bitstream
	flag_position /= 32; // This gives us where in the array are we working on

	flag_holder[flag_position] |= 1 << (bit_to_set%32);
}

//PRECON: Take int array and int for position
//POSTCON: Clear flag_positition bit to 1
void unset_flag(unsigned int flag_holder[], int flag_position)
{
	int bit_to_set = flag_position;
	flag_position /= 32;

	flag_holder[flag_position] &= ~(1 << (bit_to_set%32));
}

//PRECON: Take flag holder array and flag position
//POSTCON: Returns 1 to the previously assign bit position
int check_flag(unsigned int flag_holder[], int flag_position)
{
	int bit, bit_to_set = flag_position;
	flag_position /= 32;

	if((flag_holder[flag_position] >> bit_to_set) & 1)
		bit = 1;
	else
		bit = 0;

	return bit;
}

//PRECON: Take flag_holder array
//POSTCON: Print its values to console
void display_32_flags_as_array(unsigned int flag_holder)
{
	int i = 0;

	while(i <= 31)	// Go through the whole bit steam
	{
		printf("%d", check_flag(&flag_holder, i));
		i++;
		if(i%4 == 0)	// Divider for every four bits = byte
			printf(" ");
	}
	printf("\n");
}

//PRECON: Take flag_holder array and size
//POSTCON: Print its values to console
void display_flags(unsigned int flag_holder[], int size)
{
	int i = 0;

	for(; i < size; i++)	// Go through the array and start printing the bit stream
		display_32_flags_as_array(flag_holder[i]);
}
