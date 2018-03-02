#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	int ret;
	DIR *dir;

	if(argc<2){
		printf("please input file path\n");
		return 1;
	}

	dir = opendir(argv[1]);
	if(dir == NULL){
		printf("opendir %s failed\n", argv[1]);
		return 1;
	}
	printf("opendir %s success\n", argv[1]);
	closedir(dir);

	return 0;
}
