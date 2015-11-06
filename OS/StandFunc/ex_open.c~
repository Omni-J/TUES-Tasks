#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


// Learn very well for file descriptor and buffers !!!

int main(){
	
	char buffer[20];
	int fd = open("a.txt", O_RDONLY);
	if (fd < 0){
		perror("open");
		return 1;
	}
	size_t read_return_value = read(fd, buffer, 20-1);
	if (read_return_value < 0){
		perror("read");
	}
	buffer[19] = '0';
	printf("%s\n", buffer);
	int close_return_value = close(fd);
	if (close_return_value < 0){
		perror("close"); 
		return 2;        // $.. echo $? vijdame kakvo returnva probramata
	}
	return 0;
}	

//Not completed
