#include "Manager.h"
#include <stdexcept>
#include <algorithm>

void Manager::addEvent(const Event& event) {
    auto result = events.emplace(event.getID(), event);
    if (!result.second) {
        throw std::runtime_error("Event with this ID already exists!");
    }
}

void Manager::addParticipant(const Participant& participant) {
    auto result = participants.emplace(participant.getID(), participant);
    if (!result.second) {
        throw std::runtime_error("Participant ID already exists!");
    }
}

Event* Manager::findEvent(int eventID) {
    if (events.find(eventID) == events.end())
        throw std::runtime_error("Event not found!");
    return &events.at(eventID);
}

Participant* Manager::findParticipant(int participantID) {
    if (participants.find(participantID) == participants.end())
        throw std::runtime_error("Participant not found!");
    return &participants.at(participantID);
}

void Manager::registerParticipantToEvent(int participantID, int eventID) {
    Event* ev = findEvent(eventID);
    Participant* part = findParticipant(participantID);

    if (ev->isFull())
        throw std::runtime_error("Cannot register: Event is full!");

    ev->registerParticipant(participantID);
    part->registerEvent(eventID);
}

std::vector<Event> Manager::listEventsSortedByType() const {
    std::vector<Event> sorted;
    for (const auto& pair : events)
        sorted.push_back(pair.second);

    std::sort(sorted.begin(), sorted.end(),
              [](const Event& a, const Event& b) { return a.getType() < b.getType(); });

    return sorted;
}

std::vector<Event> Manager::listEventsSortedByParticipantCount() const {
    std::vector<Event> sorted;
    for (const auto& pair : events)
        sorted.push_back(pair.second);

    std::sort(sorted.begin(), sorted.end(),
              [](const Event& a, const Event& b) {
                  return a.getRegisteredCount() > b.getRegisteredCount();
              });

    return sorted;
}
