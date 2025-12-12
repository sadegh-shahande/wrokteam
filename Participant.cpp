#include "Participant.h"

Participant::Participant(std::string name, int id)
        : name(name), participantID(id) {}

std::string Participant::getName() const { return name; }
int Participant::getID() const { return participantID; }

void Participant::registerEvent(int eventID) {
    registeredEvents.push_back(eventID);
}

std::vector<int> Participant::getRegisteredEvents() const {
    return registeredEvents;
}
