#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

QUEUE* InitQueue() {

	QUEUE* newQueue = (QUEUE*)malloc(sizeof(QUEUE));

	if (newQueue == NULL) {
		printf("cannot allocate memory for the queue");
		exit(1);
	}

	newQueue->tail = NULL;
	newQueue->head = NULL;
	return newQueue;

}

int IsQueueEmpty(QUEUE* queue) {

	return (queue->head == NULL);

}

int EnQueue(QUEUE* queue, USER user) {

	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	if (newNode == NULL) {
		printf("cannot allocate memory for the queue");
		return 1;
	}

	newNode->user = user;
	newNode->next = NULL;

	if (queue->tail == NULL)
	{
		queue->tail = newNode;
		queue->head = newNode;
	}
	//otherwise set the current tails next to newNode, and change the tail to become newNode
	else
	{
		queue->tail->next = newNode;
		queue->tail = newNode;
	}

	//newNode->next - NULL;
	//queue->tail = newNode;

	return 0;
}

USER DeQueue(QUEUE* queue) {

	NODE* current = queue->head;

	USER ReturnedUser = current->user;

	queue->head = queue->head->next;

	if (queue->head == NULL) {

		queue->tail = NULL;
	}


	free(current);

	return ReturnedUser;
}

int AddUserToQueue(QUEUE* queue, int PlayerNum) {
	
	int i = 0;
	do {

		USER NewUser;
		NewUser.faction = randomFaction();
		NewUser.level = randomLevel();
		strncpy(NewUser.name, randomName(), MAXNAME);

		if (EnQueue(queue, NewUser) == 1)
			return 1;
		i++;

	} while (i < PlayerNum);



}