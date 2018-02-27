#include <stdio.h>
#include <string.h>

main(int argc,char*argv[])
{
  int i,j;
  i = atoi(argv[1]);
  j = atoi(argv[2]);

  printf("the program name is %s\n",argv[0]);
  printf("the command line has %d argument:",argc-1);
  printf("%d%d\n",i,j);

  return 0;
}
