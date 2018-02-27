/* cqx:20170423 */
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char **argv)
{
    int sockfd;
    char recvline[1024]={0};
    struct sockaddr_in saddr;
    
    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    if(sockfd == -1){
        printf("socket fail!!!\r\n");
        return -1;
    }
    printf("socket ok!!!\r\n");

    bzero(&saddr, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(50001);
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(-1 == bind(sockfd, (struct sockaddr*)&saddr, sizeof(saddr))){
        printf("bind fail!!!\r\n");
        return -1;
    }
    printf("bind ok!!!\r\n");

    recvfrom(sockfd, recvline, 1024,0 ,NULL, NULL);
    printf("%s\r\n", recvline);
    
    close(sockfd);
}
