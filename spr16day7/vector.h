#include "status.h"

#ifndef VECTOR_H
#define VECTOR_H

typedef struct VECTOR *VECTOR;

VECTOR vector_init_default(void);
int vector_size(VECTOR hVector);
int vector_capacity(VECTOR hVector);
Status vector_push_back(VECTOR hVector, int item);
Status vector_pop_back(VECTOR hVector);
int* vector_at(VECTOR hVector, int index);
void vector_destroy(VECTOR* pVECTOR);

#endif
