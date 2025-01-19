#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#define PORT 8000

using namespace std;

int main(){
    int client_socket;
    if((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket creation failed");
        return 1;
    }

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if(connect(client_socket, (sockaddr*)&server_address, sizeof(server_address)) < 0){
        perror("connection failed");
        return 1;
    }

    char buffer[1024];
    read(client_socket, buffer, 5);

    cout << buffer;
    return 0;
}