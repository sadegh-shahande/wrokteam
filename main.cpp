#include <iostream>
#include <vector>
#include <exception>
#include "Manager.h"

// Helper function to print event details
void printEvents(const std::vector<Event>& events, const std::string& title) {
    std::cout << "\n=== " << title << " ===\n";
    std::cout << "ID\t| Capacity\t| Type\t\t| Name\n";
    std::cout << "--------------------------------------------------------\n";
    for (const auto& ev : events) {
        std::cout << ev.getID() << "\t| " 
                  << ev.getRegisteredCount() << "/" << ev.getCapacity() << "\t\t| " 
                  << ev.getType() << "\t| " 
                  << ev.getName() << "\n";
    }
    std::cout << "--------------------------------------------------------\n";
}

int main() {
    Manager manager;

    std::cout << "Starting Festival Management System...\n";

    // 1. Setup Phase: Adding Data
    try {
        std::cout << "[INFO] Adding Events...\n";
        // Event(name, id, type, capacity)
        manager.addEvent(Event("Fajr Film Festival", 101, "Cultural", 2)); // ظرفیت کم برای تست پر شدن
        manager.addEvent(Event("Tech Summit 2024", 102, "Educational", 50));
        manager.addEvent(Event("Food Bazaar", 103, "Entertainment", 100));

        std::cout << "[INFO] Adding Participants...\n";
        manager.addParticipant(Participant("Ali Rezaei", 1));
        manager.addParticipant(Participant("Sara Mohammadi", 2));
        manager.addParticipant(Participant("Reza Davoodi", 3));
        manager.addParticipant(Participant("Negin Kabiri", 4));

    } catch (const std::exception& e) {
        std::cerr << "[CRITICAL ERROR] Setup failed: " << e.what() << std::endl;
        return 1; // Exit if setup fails
    }

    // 2. Logic Phase: Registrations
    std::cout << "\n[INFO] processing Registrations...\n";

    // A. Successful Registrations
    try {
        manager.registerParticipantToEvent(1, 101); // Ali -> Film (1/2)
        std::cout << " -> Ali registered for Film Festival (Success)\n";
        
        manager.registerParticipantToEvent(2, 101); // Sara -> Film (2/2) - Event Full Now
        std::cout << " -> Sara registered for Film Festival (Success)\n";

        manager.registerParticipantToEvent(3, 102); // Reza -> Tech
        std::cout << " -> Reza registered for Tech Summit (Success)\n";
    } catch (const std::exception& e) {
        std::cerr << " -> [Unexpected Error]: " << e.what() << std::endl;
    }

    // B. Exception Testing: Event Full
    std::cout << "\n[TEST] Testing 'Event Full' Exception:\n";
    try {
        manager.registerParticipantToEvent(3, 101); // Reza -> Film (Full!)
    } catch (const std::exception& e) {
        std::cerr << " -> Expected Error Caught: " << e.what() << std::endl;
    }

    // C. Exception Testing: Duplicate Registration (اگه کد منیجر اصلاح شده رو زده باشید)
    std::cout << "\n[TEST] Testing 'Duplicate Registration' Exception:\n";
    try {
        manager.registerParticipantToEvent(3, 102); // Reza -> Tech (Already registered)
    } catch (const std::exception& e) {
        std::cerr << " -> Expected Error Caught: " << e.what() << std::endl;
    }

    // D. Exception Testing: Invalid ID
    std::cout << "\n[TEST] Testing 'Invalid ID' Exception:\n";
    try {
        manager.registerParticipantToEvent(999, 102); // Non-existent user
    } catch (const std::exception& e) {
        std::cerr << " -> Expected Error Caught: " << e.what() << std::endl;
    }

    // 3. Reporting Phase: Sorted Lists
    try {
        auto sortedByType = manager.listEventsSortedByType();
        printEvents(sortedByType, "Events Sorted by Type");

        auto sortedByCount = manager.listEventsSortedByParticipantCount();
        printEvents(sortedByCount, "Events Sorted by Participant Count");
        
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] Reporting failed: " << e.what() << std::endl;
    }

    std::cout << "\nSystem Finished Successfully.\n";
    return 0;
}
