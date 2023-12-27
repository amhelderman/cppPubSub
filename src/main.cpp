#include <map>
#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <iomanip> // std::quoted

#include "cpppubsub/pubsubbroker.h"
#include "cpppubsub/subscriber.h"
#include "cpppubsub/publisher.h"
#include "cpppubsub/message.h"
#include "cpppubsub/pubsubmessage.h"


int main() {


    PubSubBroker pubSubBroker;

    Subscriber subscriber1(pubSubBroker);
    Subscriber subscriber2(pubSubBroker);

    subscriber1.subscribe("topic1");
    subscriber2.subscribe("topic2");
    
    Publisher publisher(pubSubBroker);
    publisher.publish(PubSubMessage("topic1", Message("basic", "Hello World")));

}