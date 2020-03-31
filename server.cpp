#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include <sys/stat.h>
 
#include <fcntl.h>
 
#include <errno.h>
 
#include <netdb.h>
 
#include <sys/types.h>
 
#include <sys/socket.h>
 
#include <netinet/in.h>
 
#include <arpa/inet.h>
 
#include <stdio.h>
 
#include <string.h>
 
#include <stdlib.h>
 
#include <unistd.h>

#include <stdlib.h>

#include <string>

#include <iostream>

using namespace std;

#define TTL 64
#define BUFF_SIZE 1024

void error_handling(char * message);

int main(int argc , char *argv[]){
    int receiver_socket;
    struct sockaddr_in receiver_addr;
    int str_len;
    char buff[BUFF_SIZE];

     if(argc!= 2){
        printf("Uasge : %s <PORT> ",argv[0]);
        exit(1);
    }

    //初始化receiver_socket
    receiver_socket = socket(PF_INET,SOCK_DGRAM,0);
    memset(&receiver_addr,0,sizeof(receiver_addr));
    receiver_addr.sin_family = AF_INET;
    receiver_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    receiver_addr.sin_port = htons(atoi(argv[1]));

     //绑定地址
    if(bind(receiver_socket,(struct sockaddr *)&receiver_addr,sizeof(receiver_addr)) == -1){
        error_handling("bind() error");
    }

    while(1){
	buff[0] = '\0';
        str_len = recvfrom(receiver_socket,buff,BUFF_SIZE-1,0,NULL,0);
        if(str_len < 0){
            break;
        }
	buff[str_len] = '\0';
	printf("receiving channel number: ");
        fputs(buff,stdout);
	printf("\n");

string str;
str = buff;
string command1;
string command2;

command1 = "sudo iw mon0 set channel " + str + " HT20";
command2 = "sudo iw wlan0 set channel " + str + " HT20";

cout<<command1<<endl;
cout<<command2<<endl;

system(command1.c_str());
system(command2.c_str());
system ("iwconfig");


    }
    close(receiver_socket);
return 0;
}

void error_handling(char * message){
    fputs(message,stderr);
    fputc('\n',stderr);
    exit(1);
}
