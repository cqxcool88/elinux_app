/* cqx:20170409 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    char *arg[] = {"ls","-a",NULL};
    
    if(fork() == 0){
        printf("fork1 is ok,execl\n");
        if(execl("/bin/ls","ls","-a",NULL) == -1){
            perror("execl error\n");
            exit(1);
        }
    }

    usleep(20000);
    if(fork() == 0){
        printf("fork2 is ok,execv\n");
        if(execv("/bin/ls",arg) == -1){
            perror("execv error\n");
            exit(1);
        }
    }   

    usleep(20000);
    if(fork() == 0){
        printf("fork3 is ok,execlp\n");
        if(execlp("ls","ls","-a",NULL) == -1){
            perror("execlp error\n");
            exit(1);
        }
    }

    usleep(20000);
    if(fork() == 0){
        printf("fork4 is ok,execvp\n");
        if(execvp("ls",arg) == -1){
            perror("execvp  error\n");
            exit(1);
        }
    }

    usleep(20000);
    if(fork() == 0){
        printf("fork5 is ok,execle\n");
        if(execle("/bin/ls","ls","-a",NULL,NULL) == -1){
            perror("execle error\n");
            exit(1);
        }
    }

    usleep(20000);
    if(fork() == 0){
        printf("fork6 is ok,execve\n");
        if(execve("/bin/ls",arg,NULL) == -1){
            perror("execve  error\n");
            exit(1);
        }
    }
    
    usleep(20000);
    return 0;
}
