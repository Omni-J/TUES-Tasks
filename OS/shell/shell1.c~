#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_LINE_LENGTH 516

char** parse_cmdline(const char* cmdline){
	char* cmdline_ = strdup(cmdline);
	char** result = malloc(sizeof(char*) * 100);
	int counter = 0;
	result[counter] = strtok(cmdline_, " ");
	while(result[counter]!= NULL){
		result[++counter] = strtok(NULL, " ");		
	}
	printf("%s\n", result[0]);
	return result;
}


int main() {
	int status;
	pid_t pid;
	while(status != -1) { // Stops if error occurs, othrwise expects new arg
		char *cmdline;	
		if (fgets(cmdline, MAX_LINE_LENGTH, stdin) == 0){ //Input and error hand.
			perror("Unsuccessful line read");	  
			status = -1;	
		}		
		pid = fork(); 
		if (pid < 0) { //Dealing with fork errors
			status = -1;
			perror("Unsuccessful fork");	
		} else if (pid == 0) { // Child
			char** cmd_proccesed = parse_cmdline(&cmdline);
			if(execv(cmd_proccesed[0], cmd_proccesed)!=NULL){
				perror("Unsuccessful execute");
				status = -1;
			}
			free(cmd_proccesed);
			exit(0);
		} else { //Parent
			//printf("Waiting for the child procces\n");
			if (waitpid (pid, &status, 0) != pid) { //wat
				status = -1;
			}
			// printf("Child procces finished->%d..\n",status);
		}
	}	
	return status;
}
