
#pragma once

#include <string>
#include <memory>
#include "pubsubclient.h"


class Publisher : public PubSubClient {
public:
    Publisher(PubSubBroker pubSubBroker) : PubSubClient(pubSubBroker) {}

    void publish(PubSubMessage message) override;
    void subscribe(std::string topic) override {}
};

