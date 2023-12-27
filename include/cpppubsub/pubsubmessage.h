#pragma once

#include <string>
#include "message.h"

class PubSubMessage {
public:
    PubSubMessage(std::string topic, Message message) : topic(topic), message(message) {}

    std::string getTopic() const {
        return topic;
    }

    friend std::ostream& operator<<(std::ostream& os, const PubSubMessage& pubSubMessage) {
        os << "PubSubMessage: " << pubSubMessage.topic << " " << pubSubMessage.message;
        return os;
    }

private:
    std::string topic;
    Message message;
};
