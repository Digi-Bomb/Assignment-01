#pragma once
#define MAXLEVEL 59
#define MAXNAME 10
#define MAXFACTIONS 3

#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

//uses enum for simplicity
typedef enum faction {

	red, blue, green

}FACTION;

//structure of our user, with a name, int, and a faction
typedef struct user {

	char name[MAXNAME];
	int level;
	FACTION faction;

}USER;

int randomLevel();
char* randomName();
int randomFaction();