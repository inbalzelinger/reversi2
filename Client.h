//
// Created by inbal on 05/12/17.
//

#ifndef REVERSITESTS_CLIENT_H
#define REVERSITESTS_CLIENT_H


class Client {
public:
    Client(const char* serverIp , int serverPort);
    void  connectToServer();
    int sendMove(char msg[7]);

    int getSocket();

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};


#endif //REVERSITESTS_CLIENT_H
