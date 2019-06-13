/*************************************************************************
    > File Name: test_fork1.c
    > Author: 黄志强
    > Mail: 2069085311@qq.com 
    > Created Time: 2019年04月26日 星期五 14时15分55秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main()
{
	//请问下面两种情况下，各打印出几个a
	int i = 0;
	for(; i < 2 ; ++i){
		//fork();//fork放在这 8 6
		printf("a");
		//printf("a\n");
		fork();//fork放在这 8 3
	}
	return 0;
}
