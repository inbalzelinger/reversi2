//
// Created by inbal on 05/12/17.
//

#include "Client.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

using namespace std;

Client::Client(const char *serverIp, int serverPort): serverIP(serverIp) ,
serverPort(serverPort) , clientSocket(0){
}

void Client::connectToServer() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    struct in_addr address;

    if (!inet_aton(serverIP, &address)) {
        throw "cant parse IP address";
    }
    struct hostent *server;
    server = gethostbyaddr((const void*) &address, sizeof(address), AF_INET);
    if (server == NULL) {
        cout<<h_errno<<endl;
        throw "Host is unreachable";
    }

    struct sockaddr_in serverAddress;
    bzero((char *) &address, sizeof(address));

    serverAddress.sin_family = AF_INET;

    memcpy((char *) &serverAddress.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

    serverAddress.sin_port = htons(serverPort);

    if (connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == 1) {
        throw "Error connecting to server";

    }

    cout << "connected to server" << endl;
}

int Client::sendMove(int arg1, int arg2) {
    int n = write(clientSocket , &arg1 , sizeof(arg1));
    if(n == -1) {
        throw "Error writing x to socket";
    }
    n = write(clientSocket , &arg2 , sizeof(arg2));
    if(n == -1) {
        throw "Error writing x to socket";
    }

}
    int Client::getSocket() {
    return this->clientSocket;
}




