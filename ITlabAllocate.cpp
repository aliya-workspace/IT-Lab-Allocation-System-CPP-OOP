#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class User {
protected:
    string name;
public:
    User(string n) {
        name = n;
    }
    virtual void showRole() = 0;
};
class Admin : public User {
public:
    Admin(string n) : User(n) {}
    void showRole() {
        cout << "Logged in as: ADMIN (" << name << ")\n";
    }
};
class Instructor : public User {
public:
    Instructor(string n) : User(n) {}
    void showRole() {
        cout << "Instructor: " << name << endl;
    }
    string getName() {
        return name;
    }
};
class LabAssistant {
    string name;
public:
    LabAssistant(string n) {
        name = n;
    }
    void showAssistant() {
        cout << "Lab Assistant on Duty: " << name << endl;
    }
};
class LabAllocation {
    string day;
    string time;
    string instructorName;
public:
    static int totalAllocations;
    LabAllocation(string d, string t, string i) {
        day = d;
        time = t;
        instructorName = i;
        totalAllocations++;
    }
    void saveToFile() {
        ofstream file("allocations.txt", ios::app);
        if (!file) {
            throw runtime_error("File opening failed!");
        }
        file << "Day: " << day
             << ", Time: " << time
             << ", Instructor: " << instructorName << endl;

        file.close();
    }
    friend void showTotalAllocations();
};
int LabAllocation::totalAllocations = 0;
void showTotalAllocations() {
    cout << "\nTotal Lab Allocations So Far: "
         << LabAllocation::totalAllocations << endl;
}
int main() {
    cout << "=====================================\n";
    cout << "   WELCOME TO IT LAB ALLOCATION SYSTEM\n";
    cout << "=====================================\n\n";
    Admin admin("Sir Shefan");
    LabAssistant assistant("Sir Asif");
    admin.showRole();
    assistant.showAssistant();
    Instructor instructors[2] = {
        Instructor("Mam Rimsha Mushtaq (OOP Lab)"),
        Instructor("Mam Amina Nawaz (Database Lab)")
    };
    string bookedDays[10];
    string bookedTimes[10];
    int bookingCount = 0;
    int choice;
    try {
        do {
            cout << "\n------ ADMIN MENU ------\n";
            cout << "1. Allocate Lab to Instructor\n";
            cout << "2. Show Total Allocations\n";
            cout << "3. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;
            if (choice == 1) {
                cout << "\nAvailable Instructors:\n";
                cout << "1. " << instructors[0].getName() << endl;
                cout << "2. " << instructors[1].getName() << endl;
                int insChoice;
                cout << "Select Instructor (1-2): ";
                cin >> insChoice;
                if (insChoice < 1 || insChoice > 2) {
                    cout << "Invalid Instructor Selection!\n";
                    continue;
                }
                string day, time;
                cout << "Enter Day: ";
                cin >> day;
                cout << "Enter Time Slot: ";
                cin >> time;
                bool conflict = false;
                for (int i = 0; i < bookingCount; i++) {
                    if (bookedDays[i] == day && bookedTimes[i] == time) {
                        conflict = true;
                        break;
                    }
                }
                if (conflict) {
                    cout << "\nERROR: This time slot is already booked!\n";
                    continue;
                }
                LabAllocation allocation(
                    day,
                    time,
                    instructors[insChoice - 1].getName()
                );
                allocation.saveToFile();
                bookedDays[bookingCount] = day;
                bookedTimes[bookingCount] = time;
                bookingCount++;
                cout << "\nLab Successfully Allocated!\n";
            }
            else if (choice == 2) {
                showTotalAllocations();
            }
        } while (choice != 3);
    }
    catch (exception& e) {
        cout << "System Error: " << e.what() << endl;
    }
    cout << "\nExiting System... Goodbye!\n";
    return 0;
}
