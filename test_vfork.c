#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int glob = 6;
int main()
{
		int var;
		pid_t pid;
		var = 88;

		if((pid = vfork()) < 0){
			perror("vfork error");
		}else if(pid == 0){
			glob++;
			var++;
			exit(0);
		}else{
			sleep(2);
		}

		printf("pid=%d,glob=%d,var=%d\n",getpid(),glob,var);

		return 0;
}

