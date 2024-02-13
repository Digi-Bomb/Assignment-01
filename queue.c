#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

//initialize the queue
QUEUE* InitQueue() {

	QUEUE* newQueue = (QUEUE*)malloc(sizeof(QUEUE));//allocating memory for the queue

	//if the memory was not allocated properly
	if (newQueue == NULL) {
		printf("cannot allocate memory for the queue");
		exit(1);
	}

	//our intial queue must be empty upon creation!
	newQueue->tail = NULL;
	newQueue->head = NULL;

	return newQueue;

}

//Check if the queue is empty
int IsQueueEmpty(QUEUE* queue) {

	return (queue->head == NULL);

}

int EnQueue(QUEUE* queue, USER user) {

	NODE* newNode = (NODE*)malloc(sizeof(NODE));//allocate memory for a new node

	//Validty check, making sure that the memory is allocated properly
	if (newNode == NULL) {
		printf("cannot allocate memory for the queue");
		return 1;
	}

	newNode->user = user;//insert the user data into newNode->user
	newNode->next = NULL;//the next node/item is null

	if (queue->tail == NULL)//if the tail is null, set both the head and tail equal to the new node
	{
		queue->tail = queue->head = newNode;
	}

	//otherwise insert the newNode's data into both the queue's tail and the tail->next
	else
	{
		queue->tail->next = newNode;
		queue->tail = newNode;
	}

	return 0;
}

//The "Pop" function of the queue+
USER DeQueue(QUEUE* queue) {

	NODE* current = queue->head;//establish a temporary/current node, which will be deleted

	USER ReturnedUser = current->user;//establish a user who's data we will return, using our temporary value

	queue->head = queue->head->next;//make the next item the new head

	//just in case the new head is null, set the tail to null aswell
	if (queue->head == NULL) {

		queue->tail = NULL;
	}

	free(current);//delete/free our temporary node

	return ReturnedUser;//return the user who's data we wish to be popped
}

//Function to add a user to the queue
int AddUserToQueue(QUEUE* queue, int PlayerNum) {
	
	int i = 0;//variable for the loop

	do {//loop the randomization of data, including names, levels, and factions

		USER NewUser;//establish a new user who will hold new data
		NewUser.faction = randomFaction();//obtain a random faction
		NewUser.level = randomLevel();//obtain a random level
		strncpy(NewUser.name, randomName(), MAXNAME);//obtain a random name

		if (EnQueue(queue, NewUser) == 1)//if the enqueue function fails to enqueue the new user, exit the loop!!!
			return 1;
		i++;//increase the value of i, which will increase until we exit the loop

	} while (i < PlayerNum);//as long as i is less than our defined player number, keep looping

}