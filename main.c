#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "main.h"

int loc = 0;

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
	else if (strcmp(input, "quit") == 0) {
		printf("Goodbye\n");
		return 1;
	}
	else {
		printf("I don't understand.\n");
	}
	return 0;
}

int main()
{
	char *input;
	int i = 0;
	welcome_user();
	while (i == 0) {
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


