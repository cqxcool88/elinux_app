#include <stdio.h>
#include <stdlib.h>
#include <sys/type.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <termios.h>

int main()
{
  int fd;
  char* adc = "/dev/adc"
  char buf[512];
  int len,r;
  
  memset(buf,0,sizeof(buf));
  printf("adc is ready!\n");
  
  if((fd=open(adc,O_RDWR|O_NOCTTY|O_NDELAY))<0)
	printf("open adc err!\n");
  else{
	printf("open adc success!\n");
    len = read(fd,buf,10);
    if(len == 0)
    printf("return null!\n");
    else{
	r = atoi(buf);
    r =  (int)(r*10000/4095);
	printf("res value is %d\n",r);
	}
	  
  }
}