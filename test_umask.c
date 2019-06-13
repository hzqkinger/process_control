#include<stdio.h>
#include<sys/stat.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main()
{
	umask(0);
	if(creat("hehe",RWRWRW) < 0)
		perror("create");

	umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	if(creat("haha",RWRWRW) < 0)
		perror("create");
	return 0;
}
