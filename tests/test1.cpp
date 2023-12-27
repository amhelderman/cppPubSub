#include <gtest/gtest.h>

// include everyting to test pubsubbroker, publisher, and subscriber
#include "cpppubsub/pubsubbroker.h"
#include "cpppubsub/subscriber.h"
#include "cpppubsub/publisher.h"


// Just create a pubsubbroker 
TEST(PubSubBroker, create) {
    PubSubBroker pubSubBroker;
}

// just create a subscriber 
TEST(Subscriber, create) {
    PubSubBroker pubSubBroker;
    Subscriber subscriber(pubSubBroker);
}

// just create a publisher
TEST(Publisher, create) {
    PubSubBroker pubSubBroker;
    Publisher publisher(pubSubBroker);
}

// check that the subscriber can subscribe to a topic
TEST(PubSubBroker, registerSubscriber) {
    PubSubBroker pubSubBroker;
    Subscriber subscriber1(pubSubBroker);
    Subscriber subscriber2(pubSubBroker);
    subscriber1.subscribe("topic1");
    subscriber2.subscribe("topic2");

    // check number of subscribers for each topic
    EXPECT_EQ(pubSubBroker.numSubscribers("topic1"), 1);
    EXPECT_EQ(pubSubBroker.numSubscribers("topic2"), 1);
}

// check that the publisher can publish a message
TEST(PubSubBroker, publish) {
    PubSubBroker pubSubBroker;
    Subscriber subscriber1(pubSubBroker);
    Subscriber subscriber2(pubSubBroker);
    subscriber1.subscribe("topic1");
    subscriber2.subscribe("topic2");

    Publisher publisher(pubSubBroker);
    publisher.publish(PubSubMessage("topic1", Message("basic", "Hello World")));

    // check number of subscribers for each topic
    EXPECT_EQ(pubSubBroker.numSubscribers("topic1"), 1);
    EXPECT_EQ(pubSubBroker.numSubscribers("topic2"), 1);
}
