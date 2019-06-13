#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char buf[1024] = {0};
	int fd = open(STDIN_FILENO,O_RDWR);
	int size = read(fd,buf,1024);
	printf("%d %s\n",size,buf);
	printf("%d\n",lseek(fd,0,SEEK_END));

	return 0;
}
