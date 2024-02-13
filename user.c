#include "user.h"

int randomLevel() {

	int i;
	i = rand() % MAXLEVEL + 1;
	return i;
}

char* randomName() {

	char User[MAXNAME] = { 0 };
	char a[36] = {"0123456789abcdefghijklmnopqrstuvwxyz"};

	for (int i = 0; i < (MAXNAME - 1); i++) {
		User[9] = '\0';
		int r = rand() % 36;
		User[i] = a[r];
	}
	
	return User;
}

int randomFaction() {

	int r = rand() % 3;
	return r;

}
