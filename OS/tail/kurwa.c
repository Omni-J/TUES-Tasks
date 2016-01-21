/*

Julian Stoev 11B grade #29
file purpose : realsing tail 

*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void remember_line(char *arr, int byte, int *count_found, int *hole_file){
/*
	Purpose: remembering the last 10 new line chars in array which holds the current byte in the file
	Parameters: the array , the byte num, counter for the found new line chars, and parameter which cheks if the file is longer than 10 line (helpful when writting in terminal) 
*/
	arr[*count_found] = byte;
	*count_found=*count_found+1;
	if (*count_found==11){ 
		*count_found=0;
		*hole_file=0;
	}
}

void file_close(int fd){
// closing the file
	int close_return_value = close(fd);
	if (close_return_value < 0){
		perror("Error while closing"); 
	}
}

void file_write(int argc, char *arg){
// the main workforce
	char memory; 
	char *buffer = &memory; //read() wont work until physical memory is allocated
	char new_lines[10];
	int file_size = 0, count_found=0, found=0, hole_file=1;
	ssize_t read_return_value ;
	int fd = open(arg, O_RDONLY);
	ssize_t write_return_value;
//finding the 10 line from the last to hte first
	if (fd < 0){
		perror("Error while opening");
	}
	do {	
		read_return_value = read(fd, buffer, 1);
		if (read_return_value <= 0) {
			if (read_return_value < 0){
				perror("Error while reading");
			}
			break;
		}
		else {
			file_size++;				
			if (*buffer == '\n') {
				remember_line(new_lines, file_size, &count_found, &hole_file);
			}
		}
	} while ((read_return_value != 0)&&(read_return_value != -1));
//	file_close(fd);
//	file_size=0;

// writing the title of the file 
	int i = 0;
	if(argc>1){	
	write_return_value = write(1,"\n",strlen("\n"));
	write_return_value = write(1, arg, strlen(arg));
	if (write_return_value<0){
		perror("Error while writing");
	}
	write_return_value = write(1,":\n",strlen(":\n"));
	if (write_return_value<0){
		perror("Error while writing");
	}
	}

//writing the file
	fd = open(arg, O_RDONLY);
	if (fd < 0){
		perror("Error while opening");
	}
	do {	
		read_return_value = read(fd, buffer, 1);
		if (read_return_value <= 0) {
			if (read_return_value < 0){
				perror("Error while reading");
			}
			break;
		}
		else {
			if(hole_file==0){
				file_size++;
			//	printf("  %d  ",file_size);
				if ((file_size==new_lines[count_found])||(found==1)) {
					if ((file_size!=new_lines[count_found])) {
						write_return_value = write(1, buffer, 1);
						if (write_return_value<0){
							perror("Error while writing");
						}
					}
					found=1;
				}
			}			
			else {
				write_return_value = write(1, buffer, 1);
				if (write_return_value<0){
					perror("Error while writing");
				}
			}
		}
	} while ((read_return_value != 0)&&(read_return_value != -1));
}

int main(int argc, char *argv[]) {
// dealing with arguments
	int i;
	for( i=1; i<argc; i++){
		file_write(argc, argv[i]);
	}
	return 0;
}
