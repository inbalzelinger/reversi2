//
// Created by inbal on 05/12/17.
//

#ifndef REVERSITESTS_CLIENT_H
#define REVERSITESTS_CLIENT_H

#define MSGSIZE 20
class Client {
public:
	/**
	 * constructor
	 * @param serverIp
	 * @param serverPort
	 */
    Client(const char* serverIp , int serverPort);
	~Client();
/**
 * connect the client to the server
 */
	void  connectToServer();
	/**
	 * write the player move to the server
	 * @param msg
	 * @return
	 */
    int sendMove(char msg[MSGSIZE]);
	/**
	 * return the socket
	 * @return client socket
	 */
    int getSocket();

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};


#endif //REVERSITESTS_CLIENT_H
