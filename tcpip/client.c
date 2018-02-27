/* cqx:20170416 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

main(int argc, char **argv)
{
    int cfd; 
    struct sockaddr_in c_add;   
    unsigned short port_num=0x8888; 
    int recbyte=0;
    char buffer[1024]={0};    

    printf("welcome to my client!\n");

    cfd = socket(AF_INET, SOCK_STREAM, 0);
    if(cfd == -1){
        printf("socket fial!\n");
        return -1;
    }
    printf("socket ok!\n");
    
    bzero(&c_add, sizeof(struct sockaddr_in));
    c_add.sin_family=AF_INET;
    c_add.sin_port=htons(port_num);
    c_add.sin_addr.s_addr=inet_addr(argv[1]);
    printf("port:%#x,s_addr:%#x\n", c_add.sin_port,c_add.sin_addr.s_addr);

    if(-1 == connect(cfd, (struct sockaddr *)(&c_add), sizeof(struct sockaddr))){
        printf("connet fail!\n");
        return -1;
    }
    printf("socket ok!\n");

    while(1){
        if(-1 == (recbyte=read(cfd, buffer, 1023))){
            printf("read fail!\n");
            return -1;
        }
        buffer[recbyte] = '\0';
        printf("recived:%s\n", buffer);
    }

    close(cfd);
    return 0;
}
