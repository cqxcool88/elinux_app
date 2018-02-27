/* cqx:20170423 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char **argv)
{
    int cfd; 
    struct sockaddr_in s_add;   
    char sendline[128]={0};    
   
    if(argc != 2){
        printf("usgae:./client[ip]\n");
        return -1;
    }
 
    cfd = socket(PF_INET, SOCK_DGRAM, 0);
    if(cfd == -1){
        printf("socket fial!\n");
        return -1;
    }
    printf("socket ok!\n");
    
    bzero(&s_add, sizeof(struct sockaddr_in));
    s_add.sin_family=AF_INET;
    s_add.sin_port=htons(50001);
    s_add.sin_addr.s_addr=inet_addr(argv[1]);
    printf("port:%#x,s_addr:%#x\n", s_add.sin_port,s_add.sin_addr.s_addr);

    sprintf(sendline, "hello world!!!");
    sendto(cfd, sendline, strlen(sendline), 0, (struct sockaddr*)&s_add, sizeof(s_add));

    close(cfd);
    return 0;
}
