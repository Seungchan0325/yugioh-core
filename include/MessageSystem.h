#pragma once

#include "common.h"

#include <set>

#include "Game.h"
#include "MessageDef.h"

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
    MessageListener(Game* game);
    virtual ~MessageListener();
    virtual void handleMessagae(Message msg);
private:
    Game* _game;
};

class MessagePublisher
{
public:
    MessagePublisher(Game* game);

    void addListener(MessageListener* listener);
    void removeListener(MessageListener* listener);

    void publish(const Message& msg);
    void publish(const Message& msg, MessageListener* target);
private:
    Game* _game;
    std::set<MessageListener*> _listeners;
};

}