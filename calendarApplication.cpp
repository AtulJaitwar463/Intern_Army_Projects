#include <iostream>
#include <vector>
#include <string>

// Structure to represent an event
struct Event {
    std::string date;
    std::string time;
    std::string description;
};

// Function to display the menu
void displayMenu() {
    std::cout << "\n------ Calendar/Planner Application ------\n";
    std::cout << "1. Add Event\n";
    std::cout << "2. Edit Event\n";
    std::cout << "3. Delete Event\n";
    std::cout << "4. View Events\n";
    std::cout << "5. Exit\n";
    std::cout << "----------------------------------------\n";
}

// Function to add an event
void addEvent(std::vector<Event>& events) {
    Event newEvent;
    
    std::cout << "\nEnter Date (YYYY-MM-DD): ";
    std::cin >> newEvent.date;
    
    std::cout << "Enter Time (HH:MM): ";
    std::cin >> newEvent.time;
    
    std::cin.ignore();  // Clear the buffer
    std::cout << "Enter Event Description: ";
    std::getline(std::cin, newEvent.description);
    
    events.push_back(newEvent);
    
    std::cout << "Event added successfully!\n";
}

// Function to edit an event
void editEvent(std::vector<Event>& events) {
    int index;
    
    std::cout << "\nEnter the index of the event to edit: ";
    std::cin >> index;
    
    if (index >= 0 && index < events.size()) {
        Event& eventToEdit = events[index];
        
        std::cout << "Enter New Date (YYYY-MM-DD): ";
        std::cin >> eventToEdit.date;
        
        std::cout << "Enter New Time (HH:MM): ";
        std::cin >> eventToEdit.time;
        
        std::cin.ignore();  // Clear the buffer
        std::cout << "Enter New Event Description: ";
        std::getline(std::cin, eventToEdit.description);
        
        std::cout << "Event edited successfully!\n";
    } else {
        std::cout << "Invalid index. No event found.\n";
    }
}

// Function to delete an event
void deleteEvent(std::vector<Event>& events) {
    int index;
    
    std::cout << "\nEnter the index of the event to delete: ";
    std::cin >> index;
    
    if (index >= 0 && index < events.size()) {
        events.erase(events.begin() + index);
        std::cout << "Event deleted successfully!\n";
    } else {
        std::cout << "Invalid index. No event found.\n";
    }
}

// Function to view all events
void viewEvents(const std::vector<Event>& events) {
    std::cout << "\n------ All Events ------\n";
    
    for (size_t i = 0; i < events.size(); ++i) {
        const Event& event = events[i];
        std::cout << "Index: " << i << "\n";
        std::cout << "Date: " << event.date << "\n";
        std::cout << "Time: " << event.time << "\n";
        std::cout << "Description: " << event.description << "\n";
        std::cout << "-------------------------\n";
    }
}

int main() {
    std::vector<Event> events;  // Vector to store events
    
    int choice;
    
    do {
        displayMenu();
        
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                addEvent(events);
                break;
            case 2:
                editEvent(events);
                break;
            case 3:
                deleteEvent(events);
                break;
            case 4:
                viewEvents(events);
                break;
            case 5:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
