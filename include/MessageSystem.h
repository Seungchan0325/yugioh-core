#pragma once

#include "common.h"

#include <set>

#include "Game.h"

namespace yugioh_core
{

struct Message {
    uint32_t message_type;
    uint64_t message_data;
    MessageListener informer;
};

class MessageListener
{
public:
    virtual void handleMessagae(Message msg);
private:
};

class MessagePublisher
{
public:
    MessagePublisher(Game& game);

    void addListener(MessageListener& listener);
    void removeListener(MessageListener& listener);
    void publish(const Message& msg);
    void publish(const Message& msg, MessageListener& target);
private:
    Game* _game;
    std::set<MessageListener*> _listeners;
};

}