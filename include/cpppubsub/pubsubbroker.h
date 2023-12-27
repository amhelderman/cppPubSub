#include <map>
#include <vector>
#include <iostream>
#include <memory>

// #include "pubsubclient.h"
#include "pubsubmessage.h"

# pragma once

class Subscriber;

class PubSubBroker {
public:
    void registerSubscriber(std::string topic, std::shared_ptr<Subscriber> subscriber);
    void publish( PubSubMessage message);

    // number subscribers
    int numSubscribers(std::string topic) {
        return subscribers[topic].size();
    }

private:
    std::map<std::string, std::vector<std::shared_ptr<Subscriber>>> subscribers;
};
