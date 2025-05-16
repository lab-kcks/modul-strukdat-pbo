#include <iostream>
#include <string>
using namespace std;


// Base class representing an activity
class doActivity {
public:
    // Virtual method to perform an activity
    virtual void activity(int &hunger, int &happiness) {
        cout << "\nPou is doing something..." << endl;
    }
};


// Derived class: Eating
class Eat : public doActivity {
public:
    // Overriding the activity method
    void activity(int &hunger, int &happiness) override {
        // Call the base class method
        doActivity::activity(hunger, happiness);


        // Update the hunger and happiness
        hunger -= 10;
        happiness += 5;
        cout << "Pou is eating!" << endl;
    }
};


// Derived class: Playing
class Play : public doActivity {
public:
    // Overriding the activity method
    void activity(int &hunger, int &happiness) override {
        // Call the base class method
        doActivity::activity(hunger, happiness);


        // Update the hunger and happiness
        happiness += 15;
        hunger += 15;
        cout << "Pou is playing!" << endl;
    }
};


// Pou class
class Pou {
    // Data is private
private:
    int hunger;
    int happiness;
    string name;


public:
    // Default constructor
    Pou() {
        hunger = 50;
        happiness = 5;
        name = "No Name";
    }
   
    // Setter methods (public)
    void setName(const string &pouName) {
        name = pouName;
        cout << "Pou's name is now: " << name << "!" << endl;
    }


    // Setter methods (public)
    void deleteName() {
        name = "No Name";
        cout << "Pou's name has been removed." << endl;
    }


    // Method to perform an activity
    void doActivity(doActivity &activity) {
        activity.activity(hunger, happiness);
        displayStatus();
    }


    // Method to display Pou's status
    void displayStatus() const {
        cout << "\n===============================" << endl;
        cout << "          POU STATUS          " << endl;
        cout << "===============================" << endl;
        cout << "Name: " << name << endl;
        cout << "Hunger: " << hunger << endl;
        cout << "Happiness: " << happiness << endl;
        cout << "===============================\n" << endl;
    }
};


int main() {
    // Create objects
    Pou myPou;
    Eat eating;
    Play playing;


    // Menu
    int choice;
    do {
        cout << "\nPOU" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Eat" << endl;
        cout << "2. Play" << endl;
        cout << "3. Set Pou's Name" << endl;
        cout << "4. Delete Pou's Name" << endl;
        cout << "5. Check Pou's Status" << endl;
        cout << "6. Exit" << endl;
        cout << "---------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();


        switch (choice) {
        case 1:
            myPou.doActivity(eating);
            break;
        case 2:
            myPou.doActivity(playing);
            break;
        case 3: {
            string pouName;
            cout << "Enter a name for Pou: ";
            getline(cin, pouName);
            myPou.setName(pouName);
            break;
        }
        case 4:
            myPou.deleteName();
            break;
        case 5:
            myPou.displayStatus();
            break;
        case 6:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 6." << endl;
        }
    } while (choice != 6);


    return 0;
}
