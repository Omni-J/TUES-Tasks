#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **argv) {

	pid_t pid = fork();
	if (pid == 0) {
		printf("Hello from child!\n");
		return 9;
	} else if (pid > 0) {
		printf("Hello from parent!\n");

		printf("Waiting for child process..\n");

		int status = 0;
		wait(&status);

		if (WIFEXITED(status)) {
			int exit_status = WEXITSTATUS(status);
			printf("Child process '%d' terminated normally with exit status code: %d\n", pid, exit_status);
		} else {
			printf("Child process exited abnormally!\n");
			return 1;
		}
	} else {
		perror("fork");
		return 1;
	}

	return 0;
}
