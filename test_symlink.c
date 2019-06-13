#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
//	symlink("file","fff");

	int fd = open("fff",O_RDONLY);  //open函数是跟随符号链接的
	char buf[1024] = {0};
	read(fd,buf,30);
	printf("%s\n",buf);

	memset(buf,0,1024);
	readlink("fff",buf,30);   //readlink函数是不跟随符号链接的
	printf("%s\n",buf);

	return 0;
}
