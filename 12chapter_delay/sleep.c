#include <stdio.h>
#include <unistd.h>

main()
{
  int i = 10;
  while(i--){
    sleep(2);
	printf("sleep 2!\n");
	usleep(1000000);
	printf("usleep 1000000!\n");
  }  
}