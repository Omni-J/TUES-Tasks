#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	char buffer[20], buffer_help[200];
	int fd = open("a.txt", O_RDONLY);
	
	ssize_t read_return_value;
	
	if (fd < 0){
		perror("open");
		return 1;
	}
	do{
		 read_return_value = read(fd, buffer, 20 - 1);
		 printf("%s", buffer);
		 if(read_return_value == 0)
		 {
		 
		 	buffer[19] = '\0';
		 	 
		 }
		
	}while(read_return_value != 0);	
	
printf("\n");
	if (read_return_value < 0){
		perror("read");
		return 2;
	}
	int close_return_value = close(fd);
	if (close_return_value < 0){
		perror("close"); 
		return 3;   
	}

	return 0;
}
