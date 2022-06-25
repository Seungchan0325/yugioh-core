#include "common.h"

#include "Game.h"
#include "MessageSystem.h"

namespace yugioh_core
{

Game::Game() {
    _publisher = new MessagePublisher(this);
}

void Game::initialize() {
    _publisher->publish({
        .message_type = MSG_INITIALIZE_GAME
    });
}

void Game::start() {
    initialize();
    
    _publisher->publish({
        .message_type = MSG_START_GAME
    });
}

void Game::end() {
    _publisher->publish({
        .message_type = MSG_END_GAME
    });
}

MessagePublisher* Game::getMessagePublisher() {
    return _publisher;
}

}