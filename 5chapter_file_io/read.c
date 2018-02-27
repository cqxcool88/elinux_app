#include <stdio.h>
#include <sys/type.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 100

main(){
  int fd;
  char *testwrite = "/bin/testwrite";
  ssize_t len_w, len_r=MAX_SIZE,ret;
  char buf_w[] = "hello write function!";
  char buf_r[MAX_SIZE]; 

  if((fd = open(testwrite,O_RDWR|O_CREAT,0777))<0){
    printf("open %s failed!\n",testwrite);
  }

  len_w = write(fd,buf_w,strlen(buf_w));
  if(len_w == -1){
    perror("write");
  }  
  else{
    printf("write function ok!\n");
  }
  close(fd);

  if((fd = open(testwrite,O_RDWR|O_CREAT,0777))<0){
    printf("open %s failed!\n",testwrite);
  }

  if(ret = read(fd,buf_r,len_r)){
    perror("read");
  }
  printf("file content is %s\n",buf_r);
  close(fd);
}
