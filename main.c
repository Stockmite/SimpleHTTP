#include <winsock2.h>
#include <Windows.h>
#include <ws2def.h>

int main() {

    WSADATA wsadata;
    WSAStartup(MAKEWORD(2,2), &wsadata);

    SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = 0;
    addr.sin_port = htons(8080);

    bind(ServerSocket, &addr, sizeof(addr));

    listen(ServerSocket, 5);

    SOCKET ClientSocket = accept(ServerSocket, 0, 0);

}