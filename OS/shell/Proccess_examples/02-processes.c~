#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
	printf("Hello world!\n");

	char* args[] = {
		"ls",
		"-l",
		NULL
	};

	execv("/bin/ls", args);

	perror("execv");
	
	printf("Goodbye world!\n");

	return 0;
}
