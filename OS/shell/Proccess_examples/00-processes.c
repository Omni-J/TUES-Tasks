#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **argv) {

	pid_t pid = fork();
	if (pid == 0) {
		printf("Hello from child!\n");
	} else if (pid > 0) {
		printf("Hello from parent!\n");
	} else {
		perror("fork");
		return 1;
	}

	return 0;
}
