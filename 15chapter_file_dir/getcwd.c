#include <stdio.h>
#define __USR_GNU
#include <unistd.h>

#define LENTH 255

int main(int arfc, char *argv[])
{
	char pwd[LENTH];
	char *wd;

	if(!getcwd(pwd, LENTH)){
		perror("getcwd\n");
		return 1;
	}
	printf("getcwd pwd is %s\n", pwd);

	wd = getwd(pwd);
	if(!wd){
		perror("getwd\n");
		return 1;
	}
	printf("getwd is %s\n", wd);

	wd = get_current_dir_name();
	if(!wd){
		perror("get_current_dir_name\n");
		return 1;
	}
	printf("get_current_dir_name is %s\n", wd);

	return 0;
}
