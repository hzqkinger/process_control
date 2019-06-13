#include<stdio.h>
#include<unistd.h>

int glob = 6;
char buf[] = "a write to stdout\n";
char buf2[100];
int main()
{
		int var;
		pid_t pid;
		var = 88;

//		if(write(STDOUT_FILENO,buf,sizeof(buf)-1) != sizeof(buf) - 1)
//				perror("write error");
//		printf("befork fork");
//		printf("befork fork\n");

//		FILE *fp = fopen("file","rw");


		if((pid = fork()) < 0){
			perror("fork error");
		}else if(pid == 0){
			glob++;
			var++;
			printf("in child:pid=%d,getpid()=%d\n",pid,getpid());
//			fread(buf2,5,6,fp);
//			buf2[30] = '\0';
//			printf(buf2);
		}else{
			sleep(2);
			printf("in parent:pid=%d,getpid()=%d\n",pid,getpid());
//			fread(buf2,5,6,fp);
//			buf2[30] = '\0';
//		printf(buf2);
		}

		printf("pid=%d,glob=%d,var=%d\n",getpid(),glob,var);

		return 0;
}
//1.子进程是父进程的副本，例如，子进程获得父进程数据空间，堆，栈的副本（主要是数据结构的副本）。
//   父子进程不共享这些存储空间部分。父子进程共享正文段。
//2.全缓冲，行缓冲，无缓冲
//  write是不带缓冲的；标准I/O是带缓冲的，如果标准输出到终端设备，则他是行缓冲，否则是全缓冲。
//3.文件共享
