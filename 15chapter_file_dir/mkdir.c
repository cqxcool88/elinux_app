#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main (int argc, char *argv[])
{
	int ret;

	if(argc<2){
		printf("please input file path\n");
		return 1;
	}
	
	ret = mkdir(argv[1], 0755);
	if(ret<0){
		printf("mkdir %s failed\n", argv[1]);
		return 1;
	}
	printf("mkdir %s success\n", argv[1]);

	return 0;
}
