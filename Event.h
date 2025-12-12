#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>

class Event {
private:
    std::string eventName;
    int eventID;
    std::string eventType;
    int capacity;
    std::vector<int> registeredParticipants;

public:
    Event(const std::string& name, int id, const std::string& type, int cap);

    std::string getName() const;
    int getID() const;
    std::string getType() const;
    int getCapacity() const;
    int getRegisteredCount() const;

    void registerParticipant(int participantID);
    bool isFull() const;
};

#endif
