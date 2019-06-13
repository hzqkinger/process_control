#include<stdio.h>
#include<unistd.h>

int main(int argc,char*argv[])
{
	truncate(argv[1],40);
	return 0;
}
