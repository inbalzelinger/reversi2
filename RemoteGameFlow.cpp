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
    cin.ignore();
    do {
		try {
			this->client->connectToServer();
		} catch (const char* error) {
			cout<<error;
			return;
		}
        consoleDisplay.showRemoteMenu();
        string msg;
        getline(cin, msg);
        istringstream iss(msg);
        string commandName;
        string tmp;
        stringstream ss;
        iss>>commandName;
        cout << commandName << endl;
        if (strcmp("start", commandName.c_str()) == 0) {
            bool find= this->start(msg);
            feedback = !find;
        } else if (strcmp("join", commandName.c_str()) == 0) {
            bool find=this->join(msg);
            feedback=!find;
        } else if (strcmp("list_games", commandName.c_str()) == 0) {
            this->game_list(msg);
        }
    } while (feedback) ;

}



bool RemoteGameFlow::join(string name) {
    char symbol;
    char msg[20];
    strcpy(msg , name.c_str());
    int n = write(client->getSocket() , &msg , MSGSIZE);
    n = read(client->getSocket(), &symbol, sizeof(char));
    if (n == -1) {
        cout << "ERROR READING THE SYMBOL" << endl;
        return false;
    }
    if(symbol=='0'){
        cout<<"can't find this game"<<endl;
        return false;
    }
    if(symbol=='e'){
        cout<<"server is close"<<endl;
        exit(0);
    }
    cout<<"in join"<<symbol;
    RemoteGameLevel remoteGameLevel(*client,consoleDisplay,symbol);
    remoteGameLevel.play();
}


bool RemoteGameFlow::start(string name) {
    char msg[MSGSIZE];
    char feedback;
    strcpy(msg, name.c_str());
    cout<<"send in start: "<<msg<<endl;
    //this->client->sendMove(msg);
    int n = write(client->getSocket() , &msg , MSGSIZE);
     n = read(client->getSocket(), &feedback, sizeof(feedback));
    if (n == -1) {
        cout << "ERROR READING THE SYMBOL" << endl;
    }
    if(feedback=='e'){
        cout<<"server is close"<<endl;
        exit(0);
    }
        if (feedback == '1') {
        this->consoleDisplay.firstConnectionMassage();
        int n = read(client->getSocket(), &feedback, sizeof(feedback));
        if (n == -1) {
            cout << "ERROR READING THE SYMBOL" << endl;
        }
        if(feedback=='e') {
            cout << "server is close" << endl;
            exit(0);
        }
        RemoteGameLevel remoteGameLevel(*client, consoleDisplay, feedback);
        remoteGameLevel.play();
        return true;
    }
    else if(feedback=='0'){
            cout<<"game already exist"<<endl;
            return false;
        }
}


bool RemoteGameFlow::game_list(string name){

    char msg[MSGSIZE];
    char feedback[150];
    strcpy(msg, name.c_str());
    //this->client->sendMove(msg);
    int n = write(client->getSocket() , &msg , MSGSIZE);
    //this->client->readMove(feedback);
    n = read(client->getSocket(), &feedback, 150);
    if(feedback[0]=='e') {
        cout << "server is close" << endl;
        exit(0);
    }
    cout<<"game list: "<<feedback<<endl;

}

RemoteGameFlow::~RemoteGameFlow() {
    delete client;
}


