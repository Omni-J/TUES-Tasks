//#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

void write_title(char *arg){
	ssize_t write_status;
	write_status = write(1, "\n", 1);
	write_status = write(1, arg, strlen(arg));
	write_status = write(1, ":", 1);
	write_status = write(1, "\n", 1);
	if (write_status == -1){
		perror("Error while writing title");
	}	
}

void write_head(char *arg){
	char memory;
	char *buff = &memory;
	int fd = open(arg, O_RDONLY);
	if(fd == -1){
		perror("Error while opening");
	}
	
	write_title(arg);
	
	ssize_t read_status, write_status;
	int nl_count = 0;
	do {
		read_status = read(fd, buff, 1);
		if (read_status == -1){
			perror("Error while reading");
		}
		if (*buff == '\n'){
			nl_count++;
		}
		if((nl_count <= 10)&&(read_status != 0)){
			write_status = write(1, buff, 1); // fd = 1 = stdout
			if(write_status == -1){
				perror("Error while writing");
			}
		}
	} while ((read_status != 0)&&(nl_count != 10));
}
	

int main(int argc, char *argv[]){
	int i;
	for (i = 1; i < argc; i++){
		write_head(argv[i]);
	}
}
