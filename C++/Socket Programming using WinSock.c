#include<stdio.h>
#include<ws2tcpip.h>
#include<winsock2.h>
#include<stdlib.h>
#include<string.h>
#define PORT 8080
#pragma comment(lib,"ws2_32.lib")
int main(){
    WSADATA wsaData;
    SOCKET sock_server,sock_client;
    struct addrinfo hints,*res;
    struct sockaddr_in client;
    char data[1024];
    int client_len=sizeof(client);
    
    if (WSAStartup(MAKEWORD(2,2),&wsaData)!=0) //INITIALIZING WINDOWS SOKCET
    {
        printf("WSAStartup failed.\n");
        WSACleanup();
        return 0;
    }
    memset(&hints,0,sizeof(hints));
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_flags=AI_PASSIVE;
    if (getaddrinfo(NULL,8080,&hints,&res)!=0)
    {
        printf("getaddrinfo failed.\n");
        WSACleanup();
        return 1;
    }
    
    //CREATING SOCKET
    sock_server=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
        if (sock_server==INVALID_SOCKET)
        {
            printf("Socket not created.\n");
            WSACleanup();
            return 1;
        }
        if (bind(sock_server,res->ai_addr,(int)res->ai_addrlen)==SOCKET_ERROR)
        {
            printf("Bind failed.\n");
            WSACleanup();
            closesocket(sock_server);
            return 1;
        }
        freeaddrinfo(res);
        //listen for incoming connections
        if(listen(sock_server,SOMAXCONN)==SOCKET_ERROR){
            printf("ERror listrnin,error code %d",WSAGetLastError());
            closesocket(sock_server);
            WSACleanup();
            return 1;
        }
        printf("Server listening on port %s...\n",PORT);
        //ACCEPT CLIENT CONECTION
        sock_client=accept(sock_server,(struct sockaddr*)&client,&client_len);
        if (sock_client==INVALID_SOCKET)
        {
            printf("Error connecting to client, error code %d",WSAGetLastError());
            closesocket(sock_server);
            WSACleanup();
            return 1;
        }
         // Receive data from the client
    int recv_size = recv(sock_client, data, sizeof(data) - 1, 0);
    if (recv_size == SOCKET_ERROR) {
        printf("Receive failed: %d\n", WSAGetLastError());
        closesocket(sock_client);
        closesocket(sock_server);
        WSACleanup();
        return 1;
    }

    data[recv_size] = '\0'; // Null-terminate the received data
    printf("Received from client: %s\n", data);

    // Send a response back to the client
    const char *response = "Hello from server!";
    send(sock_client, response, strlen(response), 0);

    // Clean up
    closesocket(sock_client);
    closesocket(sock_server);
    WSACleanup();

    return 0;
}

        



    
    

