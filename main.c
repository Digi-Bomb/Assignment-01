#include "queue.h"

int main(int argc, char* argv[]) {

	srand(time(NULL));

	if (argc != 2) {
		printf("Too many or wrong number of arguments passed.");
		exit(1);
	}

	int PlayerNum = atoi(argv[1]);

	if (PlayerNum <= 0) {
		printf("Please enter a valid amount of users. \n");
		return 1;
	}

	QUEUE* queue = InitQueue();

	if (AddUserToQueue(queue, PlayerNum) == 1) {
		printf("Unable to add users to the queue");
		return 1;
	}

	char* UserFaction[] = { "Red", "Blue", "Green" };

	do {
		USER DisplayedUser = DeQueue(queue);
		printf("The user: %s, is level: %d, and their faction is: %s  \n", DisplayedUser.name, DisplayedUser.level, UserFaction[DisplayedUser.faction]);

		} while (!IsQueueEmpty(queue));

	return 0;
}
