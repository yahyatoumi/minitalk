#include <stdio.h>
#include <unistd.h>
int main()
{
	int fd[2];
	if (pipe(fd) == -1)
	{
		printf("pipe function failed!\n");
		return 0;
	}
	int id = fork();

}
