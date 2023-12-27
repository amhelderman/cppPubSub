#include <map>
#include <vector>
#include <iostream>
#include <memory>

#include "pubsubbroker.h"
#include "pubsubmessage.h"


// header guard using pragma c++ 
#pragma once

class PubSubClient {
public:
    PubSubClient(PubSubBroker& pubSubBroker) : pubSubBroker(pubSubBroker) {}

    virtual void publish(PubSubMessage message) = 0;
    virtual void subscribe(std::string topic) = 0;

    virtual ~PubSubClient() {}
    
protected:
    PubSubBroker& pubSubBroker;
};

