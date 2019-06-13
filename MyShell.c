#include<stdio.h>
#include<pwd.h>
#include<string.h>
#include<stdlib.h>
#include<libgen.h> //为了使用basename函数  man 3 basename


void my_strtok(char *buf,char *argv[])
{
	int len = strlen(buf);
	buf[--len] = '\0';

	int index = 0,argv_index = 0;
	while(index < len)
	{
		if(index != 0){
			if((buf[index-1] == ' ' || buf[index-1] == '\0') && buf[index] != ' ')
				argv[argv_index++] = buf + index;

			if(buf[index-1] != ' ' && buf[index] == ' ')
				buf[index] = '\0';
		}else{
			if(buf[index] != ' ')
				argv[argv_index++] = buf + index;
		}

		++index;
	}
	argv[argv_index] = NULL;
}

void Run(char *str,char *argv[])
{
 	//如果发现输入的指令是内建指令，则父进程自己执行该指令（ps:由于不知道有哪些内建指令，所以拿cd指令意思意思）
 	if(str && strcmp(str,"cd") == 0)
 	{
		if(chdir(argv[1]) < 0)
			perror("chdir");
 		return;
 	}

	//如果发现不是，则父进程创建子进程，让子进程来执行该命令
	pid_t pid = fork();
	if(pid == 0){
		execvp(str,argv);
		perror("execv");
		exit(0);
	}else if(pid > 0){
		wait(NULL);
	}else
		perror("fork");
}

void GetName()
{
	//1 得到用户名
	struct passwd *pwd;
	pwd = getpwuid(getuid());
	//1.1 
	char ch[] = "$$$";
	if(strcmp(pwd->pw_name,"root") == 0){
		ch[0] = '#';
		ch[1] = '#';
		ch[2] = '#';
	}

	//2 得到主机名
	char name_buf[256] = {0};
	gethostname(name_buf,256);
	int name_i = 0;
	while(name_buf[name_i] != '.')++name_i;
	name_buf[name_i] = '\0';

	//3 得到当前目录名
	char path_buf[256] = {0};
	getcwd(path_buf,256);
	char *ppath = path_buf;
	ppath = basename(path_buf);
//	int path_i = 0;
//	while(path_buf[path_i]){
//		if(path_buf[path_i] == '/')
//			ppath = path_buf + path_i + 1;
//		++path_i;
//	}

	char shell_buf[256] = {0};
	sprintf(shell_buf,"[%s@%s %s]%s",pwd->pw_name,name_buf,ppath,ch);
	printf(shell_buf);
	fflush(stdout);
}

int main()
{

	while(1){
		//0 动态的得到当前用户名，主机名，当前目录
		GetName();
		//1 等待用户的输入命令
		char buf[1024] = { 0 };
		fgets(buf,1024,stdin);
	
		//2 解析用户输入命令
		char *argv[100] = { 0 };
		my_strtok(buf,argv);
	
		//3 创建子进程，子进程进行程序替换，父进程等待子进程结束
		Run(argv[0],argv);
	}
	return 0;
}
