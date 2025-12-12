#include "Participant.h"
#include <stdexcept> 

Participant::Participant(const std::string& name, int id)
        : name(name), participantID(id) {
    
    if (name.empty()) {
        throw std::invalid_argument("Error: Participant name cannot be empty!");
    }
}

std::string Participant::getName() const { return name; }
int Participant::getID() const { return participantID; }

void Participant::registerEvent(int eventID) {
    registeredEvents.push_back(eventID);
}

std::vector<int> Participant::getRegisteredEvents() const {
    return registeredEvents;
}
