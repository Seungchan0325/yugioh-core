#pragma once

#include "MessageSystem.h"

namespace yugioh_core
{

class Game
{
public:
    Game();

    void initialize();
    void start();
    void end();

    MessagePublisher* getMessagePublisher();
private:
    MessagePublisher* _publisher;
};

}