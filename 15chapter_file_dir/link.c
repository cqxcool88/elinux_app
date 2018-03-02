#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int ret;

	if(argc<3){
		printf("please input file path\n");
		return 1;
	}
	
	ret = link(argv[1], argv[2]);
	if(ret){
		printf("link failed\n");
		return 1;
	}
	printf("link %s to %s success\n", argv[1], argv[2]);

	return 0;
}
