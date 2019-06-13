#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
		pid_t pid;
		if((pid = fork()) < 0){
			perror("fork error\n");
			exit(1);
		}else if(pid == 0){
			printf("this is child ");
			printf("before exec\n");
//			execlp("ls","ls",NULL);
//			execlp("test","test",NULL);   //将当前目录导入到环境变量后才可以执行成功,注意，test是可执行的二进制文件
//			execlp("myfunction.c","myfunction.c",NULL);  // .c文件好像不能放在这 
			execlp("Shell.sh","Shell.sh",NULL);   //注意，Shell.sh是一个可执行程序
			printf("after exec\n");
		}else{
			printf("this is parent\n");
		}
		return 0;
}

