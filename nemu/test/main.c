#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(void) {
	static char *line_read = NULL;

	if (line_read) {
		free(line_read);
		line_read = NULL;
	}

	/* line_read = readline("(nume) "); */
	line_read = readline(""); // this is no prompt.
	
	printf("termianl is over!\n");
}
