
// Now completed

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	char buffer[20], buffer1[20];
	int count = 0;
	int fd = open("a.txt", O_RDONLY);
	int fd1 = open("b.txt", O_RDONLY);
	ssize_t rrv, rrv1;  // rrv = read return value
	int diff = 0;
	if ((fd < 0)||(fd1 < 0)) {
		perror("Open error: ");
		return 1;
	}
	do {
		rrv = read(fd, buffer[0], 1); // WARNING
		rrv1 = read(fd, buffer1[0], 1); // WARNING
		if (buffer[0]!=buffer1[0]){
			diff = 1;
			
		}
		count++;
	} while  ((rrv!=0)&&(rrv1!=0)||(diff=1));
	if ((rrv < 0)||(rrv1 < 0)){
		perror("read");
		return 2;
	}
	int crv = close(fd); // crv : close rerutn value
	int crv1 = close(fd1);
	if ((crv < 0)||(crv1 < 0)){
		perror("close"); 
		return 3;   
	}
	printf("%d\n", count);
	
	
	
	return 0;
}
