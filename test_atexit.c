#include<stdio.h>
#include<stdlib.h>

void func1()
{
		printf("hello func1\n");
}
void func2()
{
		printf("hello func2\n");
}
int main()
{
		atexit(func1);
		atexit(func2);
		//exit(0);
		return 0;
}
