PROGRAM=game

${PROGRAM}: main.c main.h
	gcc -g -Wall -Werror -o ${PROGRAM} main.c

.PHONY: clean
clean:
	rm -f ${PROGRAM}
