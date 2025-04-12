//USING WINSOCK for TCP server
#include<stdio.h>
#include<winsock2.h>
#include<ws2tcpip.h>
#define PORT 8080
#pragma comment(lib,"ws2_32.lib")
int main(){
    WSADATA wsaData;
    int res=WSAStartup(MAKEWORD(2,2),&wsaData);
    struct sockaddr_in server,client1;
    SOCKET servers,client2;
    char buf[1024]={0};
    int len=sizeof(client1);
    if (res!=0)
    {
        printf("Socket couldnt initialize");
        return 1;
    }
    servers=socket(AF_INET,SOCK_STREAM,0);
    if (servers==INVALID_SOCKET)
    {
        printf("Socket cant be created");
        WSACleanup();
        return 1;
    }
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin_port=htons(PORT);
    if(bind(servers,(struct sockaddr *)&server,sizeof(server))==SOCKET_ERROR){
        printf("Socket cant be binded");
        closesocket(servers);
        WSACleanup();
        return 1;

    }
    if(listen(servers,1)==SOCKET_ERROR){
        printf("Socket cant be listened");
        closesocket(servers);
        WSACleanup();
        return 1;
    }
    client2=accept(servers,(struct sockaddr *)&client1,&len);
    if (client2==SOCKET_ERROR)
    {
        printf("Cant accept");
        closesocket(servers);
        WSACleanup();
        return 1;
    }
    int bytesReceived = recv(client2, buf, sizeof(buf), 0);
    if (bytesReceived > 0) {
        printf("Received: %s\n", buf);
    } else {
        printf("Failed to receive data\n");
    }
    
    closesocket(servers);
    closesocket(client2);
    WSACleanup();

    return 0;
    

}