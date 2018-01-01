

#include <unistd.h>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include "GameLevel.h"
#include "LocalVsRemote.h"
#include "RemotePlayer.h"


GameLevel::GameLevel(Board &b,int playerChoice,ConsoleDisplay &consoleDisplay): playerChoice(playerChoice),board(&b)
        ,consoleDisplay(&consoleDisplay) {
    if (playerChoice == 1) {
        this->blackPlayer = new ConsolePlayer(X);
        this->whitePlayer = new ConsolePlayer(O);
    } else if (playerChoice == 2) {
        this->blackPlayer = new ConsolePlayer(X);
        this->whitePlayer = new AIPlayer(O);
    } else if (playerChoice == 3) {
        string port, ip;
        ifstream inFile;
        /////take off the ../
        inFile.open("../settings.txt");
        getline(inFile, ip);
        getline(inFile, port);
        inFile.close();
        const char *ipCh = ip.c_str();
        client = new Client(ipCh, atoi(port.c_str()));
        client->connectToServer();
        consoleDisplay.showRemoteMenu();
        vector<string> commandArgs;
        string msg;
        cin.ignore();
        getline(cin, msg);
        istringstream str(msg);
        string commandName;
        string tmp;
        stringstream ss;
        getline(str, commandName, ' ');
        while (getline(str, tmp, ' ')) {
            commandArgs.push_back(tmp);
        }
        if (strcmp("start" , commandName.c_str()) == 0) {
            cout<<commandArgs[0]<<endl;
            this->startRemoteGame(commandArgs[0]);
        } else if (strcmp("join" , commandName.c_str()) == 0) {
            cout<<commandArgs[0]<<endl;
            this->joinRemoteGame(commandArgs[0]);
        }
    }
}



void GameLevel::playRemote() {
    int numX = 0;
    int numO = 0;
    Point p;
    Point notValid(0 , 0);
    vector<Point> optionsBlack;
    vector<Point> optionsWhite;
    while (board->count(this->blackPlayer->getSign()) != 0 &&
           board->count(this->whitePlayer->getSign()) != 0) {
        optionsBlack = this->turn(this->blackPlayer->getSign());
        if (!optionsBlack.empty()) {
            if (localPlayer==X) {
                consoleDisplay->showStepsOptions(optionsBlack);
            }
            p = blackPlayer->makeMove(optionsBlack, *this->board);
            if (!(p == notValid)) {
                this->board->addToBoard(p.getRow(), p.getCol(), blackPlayer->getSign());
                this->logic->upside(blackPlayer->getSign(), p.getRow(), p.getCol(), *this->board);
                if(localPlayer==O){
                    consoleDisplay->showRemotePlayerMove(X,p);
                }
            }
        }
        else{
            p = blackPlayer->makeMove(optionsBlack, *this->board);
        }
        optionsWhite = this->turn(this->whitePlayer->getSign());
        if (!optionsWhite.empty()) {
            if (localPlayer==O) {
                consoleDisplay->showStepsOptions(optionsWhite);
            }
            p = whitePlayer->makeMove(optionsWhite, *this->board);
            if (!(p == notValid)) {
                this->board->addToBoard(p.getRow(), p.getCol(), whitePlayer->getSign());
                this->logic->upside(whitePlayer->getSign(), p.getRow(), p.getCol(), *this->board);
                if(localPlayer==X){
                    consoleDisplay->showRemotePlayerMove(O,p);
                }
            }
        }
        else{

            p = whitePlayer->makeMove(optionsWhite, *this->board);
        }
        if (optionsBlack.empty() && optionsWhite.empty()||
            (board->count(blackPlayer->getSign())+board->count(whitePlayer->getSign()))==board->getSize()*board->getSize()) {
            char endMassage[7]={"E" "N" "D"};
            write(this->client->getSocket(), endMassage, sizeof(endMassage));
            break;
        }
    }
    numX = board->count(this->blackPlayer->getSign());
    numO = board->count(this->whitePlayer->getSign());
    cout<<*board;
    Symbol winnerSymbol=empty;
    int winnerScore=0;
    if (numX > numO) {
        winnerSymbol=X;
        winnerScore=numX;
    } else if (numO > numX) {
        winnerSymbol=O;
        winnerScore=numO;
    }
    consoleDisplay->showEndingStatus(winnerSymbol,winnerScore);
}


GameLevel::~GameLevel() {
    delete blackPlayer;
    delete whitePlayer;
    delete logic;
    delete client;

}




vector<Point> GameLevel::turn(Symbol playerSign) {
    vector<Point> playersOptions = this->logic->PossibleMoves(playerSign , *this->board);
    bool isPossibleToMove=!playersOptions.empty();
    consoleDisplay->showTurnMessage(playerSign,isPossibleToMove,*board);
    return playersOptions;
}


void GameLevel::play() {
    int numX = 0;
    int numO = 0;
    Point p;
    vector<Point> optionsBlack;
    vector<Point> optionsWhite;
    while (board->count(this->blackPlayer->getSign()) != 0 &&
            board->count(this->whitePlayer->getSign()) != 0) {
        optionsBlack = this->turn(this->blackPlayer->getSign());
        if (!optionsBlack.empty()) {
            consoleDisplay->showStepsOptions(optionsBlack);
            p = blackPlayer->makeMove(optionsBlack, *this->board);
            this->board->addToBoard(p.getRow(), p.getCol(), blackPlayer->getSign());
            this->logic->upside(blackPlayer->getSign(), p.getRow(), p.getCol(), *this->board);
        }
        optionsWhite = this->turn(this->whitePlayer->getSign());
        if (!optionsWhite.empty()) {
            consoleDisplay->showStepsOptions(optionsWhite);
            p = whitePlayer->makeMove(optionsWhite, *this->board);
            this->board->addToBoard(p.getRow(), p.getCol(), whitePlayer->getSign());
            this->logic->upside(whitePlayer->getSign(), p.getRow(), p.getCol(), *this->board);
        }
        if (optionsBlack.empty() && optionsWhite.empty()||
                (board->count(blackPlayer->getSign())+board->count(whitePlayer->getSign()))==board->getSize()*board->getSize()) {
            break;
        }
    }
    numX = board->count(this->blackPlayer->getSign());
    numO = board->count(this->whitePlayer->getSign());
    cout<<*board;
    Symbol winnerSymbol=empty;
    int winnerScore=0;
    if (numX > numO) {
        winnerSymbol=X;
        winnerScore=numX;
    } else if (numO > numX) {
        winnerSymbol=O;
        winnerScore=numO;
    }
    consoleDisplay->showEndingStatus(winnerSymbol,winnerScore);
}



void GameLevel::joinRemoteGame(string name) {
    char symbol;
    //this->client->sendMove();

    int n = read(client->getSocket(), &symbol, sizeof(symbol));
    if (n == -1) {
        cout << "ERROR READING THE SYMBOL" << endl;
    }
    if (symbol == '1') {
        this->consoleDisplay->firstConnectionMassage();
    }
    n = read(client->getSocket(), &symbol, sizeof(symbol));
    if (n == -1) {
        cout << "ERROR READING THE SYMBOL" << endl;
    }
    if (symbol == '1') {
        consoleDisplay->whoAmIMassage(symbol);
        this->blackPlayer = new LocalVsRemote(X, *client);
        this->whitePlayer=new RemotePlayer(O, *client);
        localPlayer=X;
    } else if (symbol == '2') {
        consoleDisplay->whoAmIMassage(symbol);
        this->whitePlayer = new LocalVsRemote(O, *client);
        this->blackPlayer=new RemotePlayer(X, *client);
        localPlayer=O;
    }
    this->logic = new ConsoleLogic();
}


void GameLevel::startRemoteGame(string name) {
    char msg[20] = "start";
    this->client->sendMove(msg);
}



