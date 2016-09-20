#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "vector.h"

void run_tests(VECTOR hVector, int n);
char get_user(void);
void print_vector(VECTOR hVector, int n);

int main(int argc, char* argv[])
{
	VECTOR hVector;
	int n;
	
	hVector = vector_init_default();
	
	if(hVector == NULL)
	{
		printf("Failed allocate space for the vector object!\n");
		exit(1);
	}

	fscanf(stdin, "%d ", &n);
	
	run_tests(hVector, n);
	
	print_vector(hVector, n);
	
	vector_destroy(&hVector);
	
	return 0;
}

char get_user(void)
{
	char input;

	fscanf(stdin, "%c", &input);
	
	return input;
}

void print_vector(VECTOR hVector, int n)
{
	int i;
	
	for(i = 0; i < n; i++)
	{
		if( *(vector_at(hVector, i) ) == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
}

void run_tests(VECTOR hVector, int n)
{
	STACK hChar;
	char *temp = NULL;
	char input = '\0', test = '\0';
	int i, problem;
	int count;

	for(i = 0; i < n; i++)	
	{
		count = 0;
		problem = 0;
		test = '\0';
		
		hChar = stack_init_default();
		
		if(hChar == NULL)
		{
			printf("Failed allocate space for the vector object!\n");
			exit(1);
		}
		
		do{
			input = get_user();
			
			test = '\0';

			if(input == '[' || input == '{' || input == '(') 
			{
				if(stack_push_back(hChar, input) == FAILURE)
				{
					printf("Failed to push to the vector!\n");
					exit(1);
				}
			}
			
			if(input == ']' || input == '}' || input == ')') 
			{
				temp = stack_at(hChar, stack_size(hChar) - 1 );
					if(temp != NULL)
						test = *temp;
			
				if(test == '[' && input == ']') 
					stack_pop_back(hChar);
			
				if(test == '{' && input == '}')
					stack_pop_back(hChar);
			
				if(test == '(' && input == ')') 
					stack_pop_back(hChar);

				if(test == '\0')
					problem = 2;
			}
			count++;
		}while(input != '\n' && input != EOF);

		if(stack_size(hChar) == 0 && problem != 2)
			problem = 1;
		
		if(problem == 2)
			problem = 0;
		
		if( (vector_push_back(hVector, problem)) == FAILURE)
		{
			printf("Failed to push to the vector!\n");
			exit(1);
		}
		stack_destroy(&hChar);
	}
}
