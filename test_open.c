#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
//	int fd = open("fff",O_RDONLY);//open和openat函数跟随符号链接
////	int fd = openat(AT_FDCWD,"fff",O_RDONLY|O_NOFOLLOW);
//	char buf[1024] = {0};
//	printf("curpos = %ld\n",lseek(fd,0,SEEK_CUR));
//	read(fd,buf,1024);
//	printf("curpos = %ld\n",lseek(fd,0,SEEK_CUR));
//	printf("open: %d %s\n",fd,buf);
//
//	printf("文件的大小 = %ld\n",lseek(fd,0,SEEK_END));
//	struct stat bux;
//	stat("fff",&bux);
//	printf("文件的大小：%ld\n",bux.st_size);

//	readlink("fff",buf,1024);
//	printf("readlink: %s\n",buf);

//	printf("%d\n",STDIN_FILENO);
//	printf("%d\n",STDOUT_FILENO);
//	printf("%d\n",STDERR_FILENO);

//	fpos_t pos;
//	FILE *fp = fopen("fff","r");
//	fgetpos(fp,&pos);
//	printf("%ld %d\n",pos,sizeof(fpos_t));

	char *str = "hahassss";
	int fd;
	int curpos = 0;
//	if((fd = open("file",O_RDWR|O_APPEND)) < 0)
	if((fd = open("file",O_RDWR)) < 0)
		printf("fd = %d open1 error\n",fd);
	else
		printf("fd = %d open1 success\n",fd);
	curpos = pwrite(fd,str,5,curpos);
	if((fd = open("file",O_RDWR)) < 0)
		printf("fd = %d open2 error\n",fd);
	else
		printf("fd = %d open2 success\n",fd);
	curpos = pwrite(fd,str,5,curpos);
	if((fd = open("file",O_RDWR)) < 0)
		printf("fd = %d open3 error\n",fd);
	else
		printf("fd = %d open3 success\n",fd);
	pwrite(fd,str,5,curpos);
	return 0;
}
