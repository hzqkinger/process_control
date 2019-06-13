#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>

int main()
{
		uid_t uid,euid;
		pid_t pid,ppid;
		if((pid = fork()) < 0){
			printf("%d\n",errno);
			exit(2);
		}else if(pid == 0){
			uid = getuid();//实际用户ID
			euid = geteuid();//有效用户ID
			printf("in child  实际组ID:%d  有效组ID:%d\n",getgid(),getegid());
			printf("child->pid:%d,ppid:%d,uid:%d,euid:%d\n",getpid(),getppid(),uid,euid);
			exit(0);//                                     自己的ID   父进程ID
		}else{
			uid = getuid();
			euid = geteuid();
			printf("in parent  实际组ID:%d  有效组ID:%d\n",getgid(),getegid());
			printf("parent->pid:%d,ppid:%d,uid:%d,euid:%d\n",getpid(),getppid(),uid,euid);
//                                                           自己的ID  父进程ID
			wait(NULL);
		}
		return 0;
}
