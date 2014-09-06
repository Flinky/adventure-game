#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>

#include "main.h"

int loc = 0;
int ogre = 0;
int sword = 0;

const int LOC_INVALID = -1;
const int LOC_INVENTORY = -2;

typedef struct location_t {
	char *name;
	char *desc;
	int north;
	int south;
	int east;
	int west;
} location_t;

location_t map[] = {
	{
		.name = "forest",
		.desc = "There are leaves.",
		.north = -1,
		.south = 2,
		.east = 1,
		.west = -1
	},
	{
		.name = "beach",
		.desc = "There are no leaves.",
		.north = -1,
		.south = 3,
		.east = -1,
		.west = 0
	},
	{
		.name = "cave",
		.desc = "It is very dark.",
		.north = 0,
		.south = -1,
		.east = 3,
		.west = -1
	},
	{
		.name = "pond ",
		.desc = "Your socks are now wet",
		.north = 1,
		.south = -1,
		.east = -1,
		.west = 2
	}
};

const int LOC_MAX=4;

char * accept_input()
{
	char *s = malloc(256);
	printf("Type your string here > ");
	fgets(s, sizeof(s), stdin);
	s[strlen(s) - 1] = '\0'; /* chop newline */
	return s;
}

void available_exits()
{
	int exits = 0;
	printf("available exits are: ");

	if (map[loc].north != -1) {
		printf("north"); exits++;
	}
	if (map[loc].south != -1) {
		if (exits > 0) printf(",");
		printf("south"); exits++;
	}
	if (map[loc].east != -1) {
		if (exits > 0) printf(",");
		printf("east"); exits++;
	}
	if (map[loc].west != -1) {
		if (exits > 0) printf(",");
		printf("west"); exits++;
	}

	if (exits == 0) {
		printf("none");
	}
	printf(".\n");
}

int handle_input(char *input)
{
//	printf("You said '%s'\n", input);
	if (strcasecmp(input, "hello") == 0) {
		printf("Hello yourself\n");
	}
	else if (strcmp(input, "north") == 0) {
		go_north();
	}
	else if (strcmp(input, "south") == 0) {
		go_south();
	}
	else if (strcmp(input, "east") == 0) {
		go_east();
	}
	else if (strcmp(input, "west") == 0) {
		go_west();
	}
	else if (strcmp(input, "quit") == 0) {
		printf("Goodbye\n");
		return 1;
	}
	else {
		printf("I don't understand.\n");
	}
	return 0;
}

void inform_user()
{
	//printf("You are in location %i\n", loc);
	printf("You are in a %s\n", map[loc].name);
	printf("%s\n", map[loc].desc);
	available_exits();
	object_locs();
}

void go_north()
{
	if (map[loc].north == -1) {
		printf("This place does not exist\n");
	}
	else {
		printf("You have gone north\n");
		loc = map[loc].north;
	}
}
void go_south()
{
	if (map[loc].south == -1) {
		printf("This place does not exist\n");
	}
	else {
		printf("You have gone south\n");
		loc = map[loc].south;
	}
}
void go_east()
{
	if (map[loc].east == -1) {
		printf("This place does not exist\n");
	}
	else {
		printf("You have gone east\n");
		loc = map[loc].east;
	}
}
void go_west()
{
	if (map[loc].west == -1) {
		printf("This place does not exist\n");
	}
	else {
		printf("You have gone west\n");
		loc = map[loc].west;
	}
}

int main()
{
	char *input;
	int i = 0;
	welcome_user();
	initialize_locs();
	while (i == 0) {
		inform_user();
		input = accept_input();
		i = handle_input(input);
		free(input);
		move_ogre();
	}
	return 0;
}

void move_ogre()
{
	int dir = rand()%4;
	int moved = 0;
	if (dir == 0 && map[ogre].north != LOC_INVALID) {
		ogre = map[ogre].north;
		moved = 1;
	}
	if (dir == 1 && map[ogre].south != LOC_INVALID) {
		ogre = map[ogre].south;	
		moved = 1;
	}
	if (dir == 2 && map[ogre].east != LOC_INVALID) {
		ogre = map[ogre].east;	
		moved = 1;
	}
	if (dir == 3 && map[ogre].west != LOC_INVALID) {
		ogre = map[ogre].west;	
		moved = 1;
	}
	if (moved && loc == ogre) printf("The ogre arrives!\n");
}

void initialize_locs() 
{
	srand(time(NULL));
	ogre = rand()%LOC_MAX;
	sword = rand()%LOC_MAX;
	loc = rand()%LOC_MAX;
}

void object_locs()
{
	if (loc == ogre) {
		printf("You see an ogre!!\n");
	}
	if (loc == sword) {
		printf("There is a shimmering sword ahead!\n");
	}
}

void welcome_user()
{
	printf("Welcome, User!\n");
}
