#include "user.h"

//generate a random level
int randomLevel() {

	int i;
	i = rand() % MAXLEVEL + 1;//the "+1" ensures that level zero isn't possible
	return i;
}

//generate a random name
char* randomName() {

	char User[MAXNAME] = { 0 };
	char a[36] = {"0123456789abcdefghijklmnopqrstuvwxyz"};//use an array of 36 (26 letters and 10 numbers)

	//Loop the random generation 10 times
	for (int i = 0; i < (MAXNAME - 1); i++) {
		int r = rand() % 36;//generate a random number from 0 through 36
		User[i] = a[r];//use the random number to insert that location into the username
	}
	
	return User;
}

//generate a random faction, from 1 to 3
int randomFaction() {

	int r = rand() % 3;
	return r;

}
