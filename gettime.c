#include <stdio.h>
#include <time.h>

main()
{
  time_t timep;
  
  time(&timep);
  printf("utc time:0x%08x\n",timep);
  timep = time(NULL);
  printf("utc time:0x%08x\n",timep);
  
  return 0;
}