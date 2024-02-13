#pragma once
#include "user.h"

//create a struct for a node, with a user and a pointer tot he next node
typedef struct node {

	USER user;
	struct node* next;

}NODE;

//build a struct for a queue, with a head and a tail
typedef struct queue {

	NODE* head;
	NODE* tail;

}QUEUE;



//Queue functions
QUEUE* InitQueue();
int IsQueueEmpty(QUEUE* queue);
int EnQueue(QUEUE* queue, USER user);
USER DeQueue(QUEUE* queue);
int AddUserToQueue(QUEUE* queue, int PlayerNum);