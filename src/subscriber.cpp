#include <iostream>
#include <iomanip> // std::quoted

#include "cpppubsub/subscriber.h"
#include "cpppubsub/message.h"
#include "cpppubsub/pubsubmessage.h"

void Subscriber::receive(PubSubMessage m) {
    std::cout << "Received message " << m << std::endl;
}

void Subscriber::subscribe(std::string topic)  {
    pubSubBroker.registerSubscriber(topic, std::shared_ptr<Subscriber>(this));
}
