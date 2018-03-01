/* cqx:2018/2/26 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <scntl.h>
#include <unistd.h>
#include <string.h>

void main()
{
	int fd;
	char *uart3 = "/dev/ttySAC3";

	if((fd = open(uart3, O_RDWR|O_CREAT, 0777))<0){
		pritf("open %s failed!\n", uart3);
	}
	else{
	printf(open %s is success!\n", uart3);
	}
}

