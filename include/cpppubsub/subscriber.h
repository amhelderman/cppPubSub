# pragma once 

#include <string>
#include <memory>
#include "pubsubclient.h"


class Subscriber: PubSubClient  {
public:
    Subscriber(PubSubBroker pubSubBroker) : PubSubClient(pubSubBroker) {}

    void subscribe(std::string topic) override;
    void publish(PubSubMessage message) override {}
    void receive(PubSubMessage message);

    ~Subscriber() = default;
};
