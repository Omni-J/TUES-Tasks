#include <sys/stat.h>
#include <fcntl.h>
//#include <stdio.h>
#include <unistd.h>
#include <string.h>

void close_file(int *fd){
	ssize_t close_return_value = close(*fd);
	if (close_return_value < 0){
		perror("Error while closing"); 
	}
}

void write_title(char *arg){
	ssize_t write_return_value;
	write_return_value = write(1, "\n", 1);
	write_return_value = write(1, arg, strlen(arg));
	write_return_value = write(1, ":\n", 2);
	if (write_return_value<0){
		perror("Error while writing");
	}
}

void write_lines(char *arg){
	int fd;
	if (*arg == '-'){
		fd = 0;
	}
	else {
		fd = open(arg, O_RDONLY);
	}
	if (fd < 0){
		perror("Error while opening");
	}

	ssize_t read_status, seek_status, write_status;
	char memory; 
	char *buffer = &memory;
	int nl_count = 0;

	seek_status = lseek(fd, 0, SEEK_END);
	if (seek_status == -1){
		perror("Error while seeking");
	}

	do {
		seek_status = lseek(fd, -1, SEEK_CUR);
		if (seek_status == -1) {break;}
		read_status = read(fd, buffer, 1);
		if (read_status == -1){
			perror("Error while reading");
		}
		seek_status = lseek(fd, -1, SEEK_CUR);
		if (*buffer == '\n') {
			nl_count++;
		}
	} while (nl_count != 11);

	write_title(arg);	

	if(seek_status != -1) { lseek(fd, 1, SEEK_CUR); }
	do {
		read_status = read(fd, buffer, 1);
		if (read_status == -1){
			perror("Error while reading");
		}
		if (read_status == 0) {
			break;
		}
		write_status = write(1, buffer, 1);
		if (write_status == -1){
			perror("Error while writing");
		}
	} while((read_status > 0)&&(write_status != -1));
	
	close_file(&fd);
}

int main(int argc, char *argv[]){
	int i;
	for(i = 1; i < argc; i++){
		write_lines(argv[i]);
	}
			
	return 0;
}
