#include "Event.h"
#include <stdexcept>

// IMPROVEMENT: Updated constructor signature & Added Input Validation
Event::Event(const std::string& name, int id, const std::string& type, int cap)
        : eventName(name), eventID(id), eventType(type), capacity(cap) {
    
    // Check if capacity is valid
    if (cap <= 0) {
        throw std::invalid_argument("Error: Capacity must be a positive number!");
    }
}

std::string Event::getName() const { return eventName; }
int Event::getID() const { return eventID; }
std::string Event::getType() const { return eventType; }
int Event::getCapacity() const { return capacity; }

int Event::getRegisteredCount() const {
    return registeredParticipants.size();
}

void Event::registerParticipant(int participantID) {
    if (isFull()) {
        throw std::runtime_error("Event capacity full!");
    }
    registeredParticipants.push_back(participantID);
}

bool Event::isFull() const {
    return registeredParticipants.size() >= capacity;
}
