#include <stdio.h>
#include <unistd.h>

main()
{
    pid_t pid;
    int i = 100;

    pid = fork();
    if(pid == -1){
        printf("fork failed!\n");
        return 1;
    }
    else if(pid){
        i++;
        printf("the father i:%d\n",i);
        printf("the father return value is %d\n",pid);
        printf("the father pid is %d\n",getpid());
        printf("the father ppid is %d\n",getppid());
        while(1);
    }
    else{
        i++;
        printf("the child i:%d\n",i);
        printf("the child return value is %d\n",pid);
        printf("the child pid is %d\n",getpid());
        printf("the child ppid is %d\n",getppid());
        while(1);
    }
    return 0;
}
