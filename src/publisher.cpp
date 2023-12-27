
#include "cpppubsub/publisher.h"


void Publisher::publish(PubSubMessage message)  {
    pubSubBroker.publish(message);
}
