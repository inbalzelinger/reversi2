//
// Created by hadar on 02/01/18.
//

#ifndef REVERSITESTS_REMOTEGAMEFLOW_H
#define REVERSITESTS_REMOTEGAMEFLOW_H

#include "ConsoleDisplay.h"
#include "Client.h"


class RemoteGameFlow {
public:


    RemoteGameFlow(ConsoleDisplay consoleDisplay1);
    ~RemoteGameFlow();
    void startRemoteGame();

    bool join(string name);

    bool start(string name);

    bool game_list(string name);

private:
    Client* client;
    ConsoleDisplay consoleDisplay;


};


#endif //REVERSITESTS_REMOTEGAMEFLOW_H
