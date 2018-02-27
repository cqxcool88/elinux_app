#include <stdio.h>
#include <time.h>

main()
{
  time_t timep;
  struct time tblock;
  
  time(&timep);
  printf("ctime is %s\n",ctime(&timep));
  printf("asctime is %s\n",asctime(gmtime(&timep)));
  
  tblock = localtime(&timep);
  printf("ctime is %s\n",ctime(&timep));
  printf("asctime is %s\n",asctime(tblock));
  
  return 0;
}