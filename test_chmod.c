#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>

int main()
{
	chmod("file",S_IRWXU);
	chown("file",500,500);
	return 0;
}
