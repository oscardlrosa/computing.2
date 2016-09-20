/*
 * main.c
 *
 *  Created on: Jan 29, 2016
 *      Author: Oscar De La Rosa
 *     Purpose: More practice with bit wise operators
 *      Effort: ~1hr, mostly figuring out how bit manipulation works
 */


#include <stdio.h>

void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int* flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);

int main(int argc, char* argv[])
{
	unsigned int flag_holder = 0;

	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);

	display_32_flags(flag_holder);

	unset_flag(&flag_holder, 31);
	unset_flag(&flag_holder, 3);
	set_flag(&flag_holder, 9);

	display_32_flags(flag_holder);
	return 0;
}

//PRECON: Take int pointer and int for position
//POSTCON: Set flag_positition bit to 1
void set_flag(unsigned int* flag_holder, int flag_position)
{
	*flag_holder |= 1 << flag_position;
}

//PRECON: Take int pointer and int for position
//POSTCON: Set flag_positition bit to 0
void unset_flag(unsigned int* flag_holder, int flag_position)
{
	*flag_holder &= ~(1 << flag_position);
}

//PRECON: Take flag holder value and flag position
//POSTCON: Returns 1 to the previously assign bit position
int check_flag(unsigned int flag_holder, int flag_position)
{
	int bit;

	if((flag_holder >> flag_position) & 1)
		bit = 1;
	else
		bit = 0;

	return bit;
}

//PRECON: Take flag_holder value
//POSTCON: Print it to console
void display_32_flags(unsigned int flag_holder)
{
	int i;
	for(i = 31; i >= 0; i--)
	{
		printf("%d", check_flag(flag_holder, i));
		if(i%4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
}
