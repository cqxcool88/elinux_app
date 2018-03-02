#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int ret;

	if(argc<2){
		printf("please input file path\n");
		return 1;
	}
	
	ret = unlink(argv[1]);
	if(ret){
		printf("unlink failed\n");
		return 1;
	}
	printf("unlink %s success\n", argv[1]);

	return 0;
}
