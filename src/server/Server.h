//
// Created by hadar on 05/12/17.
//

#ifndef REVERSITESTS_SERVER_H
#define REVERSITESTS_SERVER_H


class Server {

public:
    Server(int port);
    void start();
    void  stop();

private:
    int port;
    int serverSocket;

    void handleClient(int clientSocket);
};


#endif //REVERSITESTS_SERVER_H
