#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main()
{

	pid_t fork_result = fork();
	if(fork_result == 0)
	{
			printf("Hello child\n");
			sleep(1);
			return 5;
	}
	else if(fork_result > 0)
	{
			printf("Hello parent");
			sleep(10);
			int status;
			if(waitpid(fork_result, &status ,0) != - 1)
			{
				printf("child process %d", WEXITSTATUS(status));
			}
			return 3;
	}else
	{
		perror("fork");
	}

	return 0;
}
