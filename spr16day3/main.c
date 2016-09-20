/*
 * main.c
 *
 *  Created on: Jan 28, 2016
 *      Author: Oscar De La Rosa
 *     Purpose: This daily will allow you to practice more with the bit wise operators and shifts.
 *      Effort: ~1hr, mostly figuring out how bit manipulation works
 *
 */

#include <stdio.h>

void set_flag(int* flag_holder, int flag_position);
int check_flag(int flag_holder, int flag_position);

int main(int argc, char* argv[])
{
	int flag_holder = 0;
	int i;

	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);

	for(i = 31; i >= 0; i--)
	{
		printf("%d", check_flag(flag_holder, i));
		if(i%4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}

//PRECON: Take int pointer and int for position
//POSTCON: Set flag_positition bit to 1
void set_flag(int* flag_holder, int flag_position)
{
	*flag_holder |= 1 << flag_position;	//Moves to the left to the desired bit and OR, setting it to one
}

//PRECON: Take flag holder value and flag position
//POSTCON: Returns 1 to the previously assign bit position
int check_flag(int flag_holder, int flag_position)
{
	int bit;
	if((flag_holder >> flag_position) & 1)	//Moves flag_position spaces the right of flag_holder. If AND with that value equal to 1
		bit = 1;	//There's a bit there
	else
		bit = 0;	//No bit assigned

	return bit;
}
