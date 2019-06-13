#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

////////////////////////////////////// // 1.等待一个子进程：//////////////////////////////////////////////////
int main()
{
		pid_t pid;

		if((pid = fork()) < 0){
			perror("fork error");
			return 1;
		}else if(pid == 0){
				printf("child is run,pid is %d\n",getpid());
				sleep(5);
				exit(1);
		}else{
				int status = 0;
				pid_t ret;
				//ret = waitpid(-1,&status,WNOHANG);         //阻塞式等待
				do{                                          //非阻塞式等待
					ret = waitpid(-1,&status,WNOHANG);
					if(ret == 0)
							printf("child is running\n");
					sleep(1);
				}while(ret == 0);
				printf("this is test for wait\n");
				if(WIFEXITED(status) && ret == pid){
					printf("wait child 5s sucess,child return code is:%d\n",WEXITSTATUS(status));
				}else{
						printf("wait child failed\n");
				}
		}
		return 0;
}




//////////////////////////////////////////////////////2.等待多个子进程：//////////////////////////////////////////////////
// int main()
// {
// 		
// 		return 0;
// }
