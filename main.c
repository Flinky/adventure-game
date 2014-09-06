#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "main.h"

int loc = 0;

typedef struct location_t {
	char *name;
	int north;
	int south;
	int east;
	int west;
} location_t;

location_t map[] = {
	{
		.name = "forest",
		.north = -1,
		.south = 2,
		.east = 1,
		.west = -1
	},
	{
		.name = "beach",
		.north = -1,
		.south = 3,
		.east = -1,
		.west = 0
	},
	{
		.name = "cave",
		.north = 0,
		.south = -1,
		.east = 3,
		.west = -1
	},
	{
		.name = "pond ",
		.north = 1,
		.south = -1,
		.east = -1,
		.west = 2
	}
};

char * accept_input()
{
	char *s = malloc(256);
	printf("Type your string here > ");
	fgets(s, sizeof(s), stdin);
	s[strlen(s) - 1] = '\0'; /* chop newline */
	return s;
}

int handle_input(char *input)
{
	printf("You said '%s'\n", input);
	if (strcasecmp(input, "hello") == 0) {
		printf("Hello yourself\n");
	}
	else if (strcmp(input, "east") == 0) {
		go_east();
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
	printf("You are in location %i\n", loc);
	printf("You are in a %s\n", map[loc].name);
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

int main()
{
	char *input;
	int i = 0;
	welcome_user();
	while (i == 0) {
		inform_user();
		input = accept_input();
		i = handle_input(input);
		free(input);
	}
	return 0;
}

void welcome_user()
{
	printf("Welcome, User!\n");
}


