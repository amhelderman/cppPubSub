

#pragma once

class Message {
public:
    Message(std::string type, std::string value) : data{type, value} {
        meta.timestamp = "2020-01-01 00:00:00";
    }

    friend std::ostream& operator<<(std::ostream& os, const Message& message) {
        os << "Message: " << message.data.type << " " << message.data.value << " " << message.meta.timestamp;
        return os;
    }
    
private:
    struct meta {
        std::string timestamp;
    };

    struct data {
        std::string type;
        std::string value;
    };

    meta meta;
    data data;
};