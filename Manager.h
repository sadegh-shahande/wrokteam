#ifndef MANAGER_H
#define MANAGER_H

#include "Event.h"
#include "Participant.h"
#include <map>
#include <vector>

class Manager {
private:
    std::map<int, Event> events;
    std::map<int, Participant> participants;

public:
    void addEvent(const Event& event);
    void addParticipant(const Participant& participant);
    void registerParticipantToEvent(int participantID, int eventID);
    Event* findEvent(int eventID);
    Participant* findParticipant(int participantID);
    std::vector<Event> listEventsSortedByType() const;
    std::vector<Event> listEventsSortedByParticipantCount() const;
};

#endif
