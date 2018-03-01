#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	struct stat groupstat;
	int fd, ret;

	if(argc<2){
		printf("\nplease input file path \n");
		return 1;
	}
	ret = stat(argv[1], &groupstat);
	if(ret){
		printf("please make sure file path\n");
	}
	printf("stat %s of st_ino is %ld\n", argv[1], groupstat.st_ino);
	
	fd = open(argv[1], O_RDWR|O_NOCTTY|O_NDELAY);
	if(fd<0){
		printf("please make sure file path\n");
		return 1;
	}
	ret = fstat(fd, &groupstat);
	if(ret){
		printf("please make sure file path\n");
		return 1;
	}
	printf("fstat %s of st_ino is %ld\n", argv[1], groupstat.st_ino);

	ret = lstat(argv[1], &groupstat);
	if(ret){
		printf("please make sure file path\n");
	}
	printf("stat %s of st_ino is %ld\n", argv[1], groupstat.st_ino);

}
