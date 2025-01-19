#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#define PORT 8000

using namespace std;

int main(){
    int server_socket;
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Server socket creation failed ");
        return 1;
    } 

    sockaddr_in server_address;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if(bind(server_socket, (sockaddr*)&server_address, sizeof(server_address)) < 0){
        perror("Binding failed");
        return 1;
    }

    if(listen(server_socket, 3) < 0){
        perror("Listening failed");
        return 1; 
    }
    cout << "server listening on port: " << PORT << endl;


    int new_socket;
    sockaddr_in client_address;
    socklen_t client_len = sizeof(client_address);
    if((new_socket = accept(server_socket,(sockaddr*)&client_address, &client_len)) < 0){
        perror("Accept failed");
        return 1;
    }

    const char* buffer = "Hello";
    write(new_socket, buffer, 5);

    

    return 0;
}