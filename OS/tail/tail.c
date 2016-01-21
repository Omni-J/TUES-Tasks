/*

Julian Stoev 11B grade #29
file purpose : realsing tail 
NOTE: wihtout standard input
NOTE: Flushing the 11 '\n' gets us 10 lines!

*/

#include <sys/stat.h>
#include <fcntl.h>
//#include <stdio.h>
#include <unistd.h>
#include <string.h>

void close_file(int *fd){
// closing the file
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


void write_last_10_lines(int argc, char *arg){
	char memory; 
	char *buffer = &memory; //read() wont work until physical memory is allocated
	long unsigned int new_lines[11];	// Array holding the number of the byte of the last 11 '\n' in the file; From it the program extracts the 11th '\n'
	long unsigned int write_point; // Holding the byte in the file which reffers to the 11th "\n"	
	long unsigned int read_bytes_count = 0; // Counts the number of bytes read
	int count_nl_found = -1; // Helps for writing in the nl array
	int is_hole_file = 1; //A Boolean, true until 11th nl is found, helps with writing and seek 
	int fd = open(arg, O_RDONLY);
	ssize_t read_return_value, write_return_value, seek_status;

	if (fd < 0){
		perror("Error while opening");
	}

	//Finding the last 11 '\n'
	do {	
		read_return_value = read(fd, buffer, 1);
		if (read_return_value <= 0) {
			if (read_return_value < 0){
				perror("Error while reading");
			}
			break;
		} else {
			read_bytes_count++;		
			if (*buffer == '\n') {
				new_lines[count_nl_found] = read_bytes_count;
				count_nl_found++;				
				if (count_nl_found==11){ 
					count_nl_found = 0;
					is_hole_file = 0;
				}
			}
		}
	} while ((read_return_value != 0)&&(read_return_value != -1));/*(read_return_value > 0);*/
	
	//Finding the 11th '\n'
	if (is_hole_file == 0){ write_point = new_lines[count_nl_found];} 
	else if (is_hole_file == 1) {write_point = 0;}

	write_title(arg);	

	//Writing the 10 lines
	do {
		seek_status = lseek(fd, write_point, SEEK_SET);
		if (seek_status < 0){
			perror("Error while seeking");
		}
		write_point++;
		read_return_value = read(fd, buffer, 1);
		if (read_return_value < 0){
			perror("Error while reading");
		}
		write_return_value = write(1, buffer, 1);
		if (write_return_value<0){
			perror("Error while writing");
		}
	} while ((write_return_value>0)&&(write_point != read_bytes_count)&&(read_return_value>0));
	
	close_file(&fd);

}


int main(int argc, char *argv[]) {
// dealing with arguments
	int i;
	for(i=1; i<argc; i++){
		write_last_10_lines(argc, argv[i]);
	}
	return 0;
}
