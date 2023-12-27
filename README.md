v0.1

# PubSub Project

This project is an implementation of a publish-subscribe (pubsub) system using a Broker, Publisher, and Subscribers. Messages are all in memory. It allows for efficient communication between publishers and subscribers in a decoupled manner.

## Features

- **Publish-Subscribe Model**: The system follows the publish-subscribe architectural pattern, where publishers send messages to a central broker, and subscribers receive messages from the broker.
- **Decoupled Communication**: Publishers and subscribers are decoupled from each other, allowing for flexible and scalable communication between different components of a system.
- **Efficient Message Distribution**: The broker efficiently distributes messages to the relevant subscribers, ensuring that each subscriber receives only the messages it is interested in.
- **Easy Integration**: The system can be easily integrated into existing projects, providing a seamless pubsub communication layer.

## Use Cases

It's just for reference. No warranty.


## Getting Started

To build and run the project, follow these steps:

1. Clone the repository: `git clone https://github.com/amhelderman/cppPubSub.git`
2. Navigate to the project directory: `cd pubsub`
3. Build the project: 
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```
4. Run the tests: `./test_pubsub`

