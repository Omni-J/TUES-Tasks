#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/*-------------------------------------
Name: Julian Stoev
Class: 11B
Number: 29
Purpose: definitely not a simple shell
--------------------------------*/

char** parse_cmdline(const char* cmdline){
	int arg = count_arguments(cmdline);
	char* cmdline_ =  strdup(cmdline); // Better not to fuck with the constant
	char** result = malloc(sizeof(char*) * arg);
	int counter = 0;
	result[counter] = strtok(cmdline_, " \n"); // man strtok
	while(result[counter]!= NULL){
		result[++counter] = strtok(NULL, " \n");		
	}
	return result;
}

int count_arguments(char* line){ // Counting the arguments for proper memery alloc.
	int count = 0;
	while(*line){
		if (' ' == *line){ count++; }
		line++;
	}
	count++; // x delimeters but x+1 arguments !!
	return count;
}


int main() {
	int status;
	pid_t pid;
	size_t bs=0;
	while(status != -1) { // Stops if error occurs, othrwise expects new arg
		char *cmdline;	
		getline(&cmdline, &bs, stdin);	
		pid = fork(); 
		if (pid < 0) { //Dealing with fork errors
			status = -1;
			perror("Unsuccessful fork");	
		} else if (pid == 0) { // Child
			char** cmd_proccesed = parse_cmdline(cmdline);
			if(execv(cmd_proccesed[0], cmd_proccesed)!=NULL){ // execv return value only when broken
				perror("Unsuccessful execute");
				status = -1;
			}
			free(cmd_proccesed);
			exit(0);
		} else { //Parent
			if (waitpid (pid, &status, 0) != pid) { //wating the child
				status = -1;
			}
		}
	}	
	return status;
}


