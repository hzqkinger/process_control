#include<stdio.h>
#include<sys/stat.h>          //stat lstat fstat fstatat
#include<libgen.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	if(argv[1]){
		int fd;
		struct stat buf;
//		fd = open(argv[1],O_RDONLY);
		if(lstat(argv[1],&buf) < 0){                      //fstat
			perror("stat");
			return 1;
		}
		
		printf("%d\n",sizeof(buf.st_mode));
		printf("%d\n",sizeof(buf.st_ino));
		printf("%d\n",sizeof(buf.st_dev));
		printf("%d\n",sizeof(buf.st_rdev));
		printf("%d\n",sizeof(buf.st_nlink));
		printf("%d\n",sizeof(buf.st_uid));
		printf("%d\n",sizeof(buf.st_gid));
		printf("%d\n",sizeof(buf.st_size));
		printf("%d\n",sizeof(buf.st_atime));
		printf("%d\n",sizeof(buf.st_mtime));
		printf("%d\n",sizeof(buf.st_ctime));
		printf("%d\n",sizeof(buf.st_blksize));
		printf("%d\n",sizeof(buf.st_blocks));

//		printf("%d\n",buf.st_mode);
//		printf("st_mode的大小%d\n",sizeof(buf.st_mode));
//
//		printf("%d\n",buf.st_mode & S_ISUID);
//		printf("%d\n",buf.st_mode & S_ISGID);
//		printf("%d\n",buf.st_mode & S_ISVTX);
//
//		printf("%d\n",buf.st_mode & S_IRUSR);
//		printf("%d\n",buf.st_mode & S_IWUSR);
//		printf("%d\n",buf.st_mode & S_IXUSR);
//		printf("%d\n",buf.st_mode & S_IRGRP);
//		printf("%d\n",buf.st_mode & S_IWGRP);
//		printf("%d\n",buf.st_mode & S_IXGRP);
//		printf("%d\n",buf.st_mode & S_IROTH);
//		printf("%d\n",buf.st_mode & S_IWOTH);
//		printf("%d\n",buf.st_mode & S_IXOTH);
//
//		char *ptr = basename(argv[1]);
//		if(S_ISREG(buf.st_mode))
//			printf("%s is regular\n",ptr);
//		else
//			printf("%s isn't regular\n",ptr);
//	
//		printf("该文件的大小是：%d\n",buf.st_size);
//		printf("该文件的inode是：%d\n",buf.st_ino);
	}

	return 0;
}
