#include "common.h"

#include "Game.h"
#include "MessageSystem.h"

namespace yugioh_core
{

MessageListener::MessageListener(Game* game) {
    _game = game;
}

MessageListener::~MessageListener() {
    auto publisher = _game->getMessagePublisher();
    publisher->removeListener(this);
}

MessagePublisher::MessagePublisher(Game* game) {
    _game = game;
}

void MessagePublisher::addListener(MessageListener* listener) {
    _listeners.insert(listener);
}

void MessagePublisher::removeListener(MessageListener* listener) {
    _listeners.erase(listener);
}

void MessagePublisher::publish(const Message& msg) {
    for(auto& i : _listeners) {
        i->handleMessagae(msg);
    }
}

void MessagePublisher::publish(const Message& msg, MessageListener* target) {
    auto target_listener = *_listeners.find(target);
    target_listener->handleMessagae(msg);
}

}