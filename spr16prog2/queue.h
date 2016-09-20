#include "status.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct QUEUE *QUEUE;

QUEUE queue_init_default(void);
int queue_size(QUEUE hQueue);
Status queue_push_back(QUEUE hQueue, int item);
Status queue_pop_front(QUEUE hQueue);
int* queue_front(QUEUE hQueue);
void queue_list_destroy(QUEUE* pQueue);

#endif
