#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
// 用C语言如何获取当前Linux系统的用户名
// 可以使用getuid()获取用户的ID号，然后通过getpwuid函数通过用户的uid查找用户的passwd数据来获取系统登录的用户名。

void test1()
{
	struct passwd *pwd;
	pwd = getpwuid(getuid());
	printf("当前登陆的用户名为：%s\n", pwd->pw_name);
	
	char name_buf[256] = {0};
	gethostname(name_buf,256);
	printf("当前主机名为：%s\n",name_buf);
	int name_i = 0;
	while(name_buf[name_i] != '.')++name_i;
	name_buf[name_i] = '\0';

	char path_buf[256] = {0};
	getcwd(path_buf,256);
	printf("当前绝对路径为:%s\n",path_buf);
	char *ppath = path_buf;
	int path_i = 0;
	while(path_buf[path_i]){
		if(path_buf[path_i] == '/')
			ppath = path_buf + path_i + 1;
		++path_i;
	}

	char shell_buf[256] = {0};
	sprintf(shell_buf,"%s@%s %s",pwd->pw_name,name_buf,ppath);

	printf(shell_buf);
	fflush(stdout);
}
int main(void)
{
	test1();
//	struct passwd *pwd;
//	pwd = getpwuid(getuid());
//	printf("当前登陆的用户名为：%s\n", pwd->pw_name);
//	
//	char buf[256] = {0};
//	gethostname(buf,256);
//	printf(buf);
	return 0;
}
