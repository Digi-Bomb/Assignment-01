#include "queue.h"

int main(int argc, char* argv[]) {

	//start by generating a randokm time signature 
	srand(time(NULL));

	//if too many arguments are passed through main, exit
	if (argc != 2) {
		printf("Too many or wrong number of arguments passed.");
		exit(1);
	}

	int PlayerNum = atoi(argv[1]);//set our player num equal to a number defined under solution properties

	if (PlayerNum <= 0) {//validty check
		printf("Please enter a valid amount of users. \n");
		return 1;
	}

	QUEUE* queue = InitQueue();//initialize the queue

	if (AddUserToQueue(queue, PlayerNum) == 1) {//add user to the queue, and check for validity 
		printf("Unable to add users to the queue");
		return 1;
	}

	char* UserFaction[] = { "Red", "Blue", "Green" };//Declare an array of 3 typings for our faction to use later

	//Loop the "popping" of users
	do {
		USER DisplayedUser = DeQueue(queue);
		printf("The user: %s, is level: %d, and their faction is: %s  \n", DisplayedUser.name, DisplayedUser.level, UserFaction[DisplayedUser.faction]);
																												//The UserFaction array translate our enum to the text we designated it earlier
		} while (!IsQueueEmpty(queue));//as long as the queue is not empty, continue to loop

	return 0;
}
