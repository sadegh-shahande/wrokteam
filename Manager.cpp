#include "Manager.h"
#include <stdexcept>
#include <algorithm>
#include <string>

void Manager::addEvent(const Event& event) {
    auto result = events.emplace(event.getID(), event);
    if (!result.second) {

        throw std::runtime_error("Error: Event with ID " + std::to_string(event.getID()) + " already exists!");
    }
}

void Manager::addParticipant(const Participant& participant) {
    auto result = participants.emplace(participant.getID(), participant);
    if (!result.second) {
        throw std::runtime_error("Error: Participant ID " + std::to_string(participant.getID()) + " already exists!");
    }
}

Event* Manager::findEvent(int eventID) {
    if (events.find(eventID) == events.end())
        throw std::runtime_error("Error: Event ID " + std::to_string(eventID) + " not found!");
    return &events.at(eventID);
}

Participant* Manager::findParticipant(int participantID) {
    if (participants.find(participantID) == participants.end())
        throw std::runtime_error("Error: Participant ID " + std::to_string(participantID) + " not found!");
    return &participants.at(participantID);
}

void Manager::registerParticipantToEvent(int participantID, int eventID) {
    Event* ev = findEvent(eventID);
    Participant* part = findParticipant(participantID);

    if (ev->isFull())
        throw std::runtime_error("Cannot register: Event is full!");


    const std::vector<int>& currentEvents = part->getRegisteredEvents();
    for(int id : currentEvents) {
        if(id == eventID) {
             throw std::runtime_error("Participant is already registered for this event!");
        }
    }

    ev->registerParticipant(participantID);
    part->registerEvent(eventID);
}

std::vector<Event> Manager::listEventsSortedByType() const {
    std::vector<Event> sorted;

    sorted.reserve(events.size());
    
    for (const auto& pair : events)
        sorted.push_back(pair.second);

    std::sort(sorted.begin(), sorted.end(),
              [](const Event& a, const Event& b) { return a.getType() < b.getType(); });

    return sorted;
}

std::vector<Event> Manager::listEventsSortedByParticipantCount() const {
    std::vector<Event> sorted;
    sorted.reserve(events.size());

    for (const auto& pair : events)
        sorted.push_back(pair.second);

    std::sort(sorted.begin(), sorted.end(),
              [](const Event& a, const Event& b) {
                  return a.getRegisteredCount() > b.getRegisteredCount();
              });

    return sorted;
}
