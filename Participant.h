#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>
#include <vector>

class Participant {
private:
    std::string name;
    int participantID;
    std::vector<int> registeredEvents;

public:
    Participant(const std::string& name, int id);

    std::string getName() const;
    int getID() const;
    void registerEvent(int eventID);
    std::vector<int> getRegisteredEvents() const;
};

#endif
