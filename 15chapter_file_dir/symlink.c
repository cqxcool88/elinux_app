#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int ret;

	if(argc<3){
		printf("please input file path\n");
		return 1;
	}
	
	ret = symlink(argv[1], argv[2]);
	if(ret){
		printf("symlink failed\n");
		return 1;
	}
	printf("symlink %s to %s success\n", argv[1], argv[2]);

	return 0;
}
