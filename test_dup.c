#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
//	int fd1,fd2;
//	fd1 = open("file1",O_RDWR|O_CREAT,0664);
//	fd2 = open("file2",O_RDWR|O_CREAT,0664);
//	printf("fd1 = %d\nfd2 = %d\n",fd1,fd2);
//	fd1 = dup(fd2);
//	printf("fd1 = %d\nfd2 = %d\n",fd1,fd2);
//
//	int fd3 = open("file",O_RDONLY);
//	printf("%d\n",fd3);
//	const char *str = "hellllllll";
//	write(fd1,str,6);
//	write(3,str,6);
//	write(fd2,str,6);


	int fd1,fd2;
	fd1 = open("file1",O_RDWR|O_CREAT,0664);
	int fd3 = open("file",O_RDONLY);
	printf("fd3 = %d\n",fd3);
	fd2 = open("file2",O_RDWR|O_CREAT,0664);
	close(fd3);

	printf("fd1 = %d\nfd2 = %d\n",fd1,fd2);
	int fd4 = dup2(fd1,fd2);
	printf("fd4 = %d\n",fd4);
	printf("fd1 = %d\nfd2 = %d\n",fd1,fd2);
	int fd5 = open("file",O_RDONLY);
	printf("fd5 = %d\n",fd5);

	const char *str = "hellllllll";
	write(fd1,str,6);
//	write(3,str,6);
	write(fd2,str,6);

	return 0;
}
