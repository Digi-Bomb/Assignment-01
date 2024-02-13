#pragma once
#include "user.h"

typedef struct node {

	USER user;
	struct node* next;

}NODE;

typedef struct queue {

	NODE* head;
	NODE* tail;

}QUEUE;



//create the queue
QUEUE* InitQueue();
int IsQueueEmpty(QUEUE* queue);
int EnQueue(QUEUE* queue, USER user);
USER DeQueue(QUEUE* queue);
int AddUserToQueue(QUEUE* queue, int PlayerNum);