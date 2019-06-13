#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	if(access(argv[1],R_OK|W_OK) < 0)
		printf("access false\n");
	else
		printf("access true\n");

	if(faccessat(AT_FDCWD,argv[1],R_OK|W_OK,AT_EACCESS) < 0)
		printf("faccessat false\n");
	else
		printf("faccessat true\n");
	return 0;
}
