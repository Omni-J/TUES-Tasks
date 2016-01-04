#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGUMENT_SIZE 4200

char** parse_cmdline(const char* cmdline){
	
}

/*
execv(const char* filename, char* const argv[]);

pid_t waitpid(pid_t pid, int* status, int options);

*/

int main() {
	int status;
	pid_t pid;
	while(status != -1) { // Stops if error occurs, othrwise expects new arg
		char cmdline[MAX_ARGUMENT_SIZE];
		scanf("%s", cmdline);		
		pid = fork();
		if (pid < 0) {
			status = -1;
			printf("Unsuccessful fork...\n");	
		} else if (pid == 0) {
			printf("%s\n", cmdline);
			exit(0);
		} else {
			printf("Waitting for the child procces\n");
			if (waitpid (pid, &status, 0) != pid) { //wat
				status = -1;
			}
			printf("Child procces finished->%d..\n",status);
		}
	}	
	return status;
}







