#include "status.h"

#ifndef STACK_H
#define STACK_H

typedef struct STACK *STACK;

STACK stack_init_default(void);
int stack_size(STACK hStack);
int stack_capacity(STACK hStack);
Status stack_push_back(STACK hStack, char item);
Status stack_pop_back(STACK hStack);
char* stack_at(STACK hStack, int index);
void stack_destroy(STACK* pSTACK);

#endif
