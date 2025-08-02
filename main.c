#include <winsock2.h>
#include <Windows.h>
#include <ws2def.h>
#include <stdio.h>

#define Buffer_lenght 256
#define queue_len 5

int main() {

    WSADATA wsadata;
    WSAStartup(MAKEWORD(2,2), &wsadata);

    SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = 0;
    addr.sin_port = htons(8080);

    bind(ServerSocket, &addr, sizeof(addr));

    listen(ServerSocket, queue_len);

    SOCKET ClientSocket = accept(ServerSocket, 0, 0);

    char req_buffer[Buffer_lenght] = {0};
    recv(ClientSocket, req_buffer, Buffer_lenght, 0);

    if (memcmp(req_buffer, "GET / ", 6) == 0) {

        FILE* file = fopen("index.html", "r");

        char fBuffer[Buffer_lenght] = {0};
        fread(fBuffer, 1, Buffer_lenght, file);
        send(ClientSocket, fBuffer, Buffer_lenght, 0);

    }

}