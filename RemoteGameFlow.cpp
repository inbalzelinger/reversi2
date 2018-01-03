//
// Created by hadar on 02/01/18.
//

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <cstring>
#include "RemoteGameFlow.h"
#include "Client.h"
#include "GameLevel.h"
#include "RemotePlayer.h"
#include "LocalVsRemote.h"
#include "RemoteGameLevel.h"


RemoteGameFlow::RemoteGameFlow(ConsoleDisplay consoleDisplay1) {
    this->consoleDisplay=consoleDisplay1;
}

void RemoteGameFlow::startRemoteGame() {
    string port, ip;
    ifstream inFile;
    /////take off the ../
    inFile.open("../settings.txt");
    getline(inFile, ip);
    getline(inFile, port);
    inFile.close();
    const char *ipCh = ip.c_str();
    bool feedback = true;
    this->client = new Client(ipCh, atoi(port.c_str()));
    this->client->connectToServer();
    consoleDisplay.showRemoteMenu();
    string msg;
    cin.ignore();
    while (feedback) {
        getline(cin, msg);
        istringstream iss(msg);
        string commandName;
        string tmp;
        stringstream ss;
        iss>>commandName;
        cout << commandName << endl;
        if (strcmp("start", commandName.c_str()) == 0) {
            this->start(msg);
        } else if (strcmp("join", commandName.c_str()) == 0) {
            this->join(msg);
        } else if (strcmp("listGames", commandName.c_str()) == 0) {
            this->game_list(msg);
        }
    }
}



bool RemoteGameFlow::join(string name) {
    char symbol;
    char msg[20];
    strcpy(msg , name.c_str());
    this->client->sendMove(msg);
    int n = read(client->getSocket(), &symbol, sizeof(symbol));
    if (n == -1) {
        cout << "ERROR READING THE SYMBOL" << endl;
        return false;
    }
    cout<<"in join"<<symbol;
    RemoteGameLevel remoteGameLevel(*client,consoleDisplay,symbol);
    remoteGameLevel.play();
}


bool RemoteGameFlow::start(string name) {
    char msg[MSGSIZE];
    char feedback;
    strcpy(msg, name.c_str());
    this->client->sendMove(msg);

    int n = read(client->getSocket(), &feedback, sizeof(feedback));
    if (n == -1) {
        cout << "ERROR READING THE SYMBOL" << endl;
    }
    cout<<"1"<<endl;
        if (feedback == '1') {
        this->consoleDisplay.firstConnectionMassage();
        int n = read(client->getSocket(), &feedback, sizeof(feedback));
        cout << feedback;

        if (n == -1) {
            cout << "ERROR READING THE SYMBOL" << endl;
        }
        RemoteGameLevel remoteGameLevel(*client, consoleDisplay, feedback);
        remoteGameLevel.play();
        return true;
    }
}


bool RemoteGameFlow::game_list(string name){
    char msg[MSGSIZE];
    char feedback[MSGSIZE];
    strcpy(msg, name.c_str());
    this->client->sendMove(msg);
   this->client->readMove(feedback);
    cout<<feedback<<endl;
}


