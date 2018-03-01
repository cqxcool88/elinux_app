/* cqx:2018.3.1 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd, ret;

	if(argc<3){
		printf("\nplease input file path\n");
		return 1;
	}

	ret = chmod(argv[1], 0777);
	if(ret<0){
		printf("please make sure file path\n");
	}
	printf("chmod %s 0777 is success\n", argv[1]);
	
	fd = open(argv[2], O_RDWR|O_NOCTTY|O_NDELAY);
	if(fd<0){
		printf("open file failed\n");
		return 1;
	}
	printf("open file success\n");
	ret = fchmod(fd, 0555);
	if(ret){
		printf("please make sure file path\n");
		return 1;
	}
	printf("chmod %s 0555 is success\n", argv[1]);

	return 0;
}
