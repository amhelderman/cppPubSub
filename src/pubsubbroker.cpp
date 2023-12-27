#include "cpppubsub/pubsubbroker.h"
#include "cpppubsub/subscriber.h"

void PubSubBroker::registerSubscriber(std::string topic, std::shared_ptr<Subscriber> subscriber) {
    subscribers[topic].push_back(subscriber);
}

void PubSubBroker::publish(PubSubMessage message) {
    for (auto subscriber : subscribers[message.getTopic()]) {
        subscriber->receive(message);
    }
}
