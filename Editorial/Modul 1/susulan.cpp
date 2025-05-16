#include <iostream>
using namespace std;

// Base class: Building
class Building {
protected:
    string nama;
    int jumlahLantai;

public:
    Building(string n, int lantai) : nama(n), jumlahLantai(lantai) {}

    virtual void showDetails() {  // Virtual function for polymorphism
        cout << "Nama Bangunan: " << nama << endl;
        cout << "Jumlah Lantai: " << jumlahLantai << endl;
    }
};

// Derived class: ParkingSystem
class ParkingSystem : public Building {
private:
    int totalSpots[4];  // Index 1 = Big, 2 = Medium, 3 = Small
    int spotsAvailable[4];

public:
    ParkingSystem(string n, int lantai, int big, int medium, int small) 
        : Building(n, lantai) {
        totalSpots[1] = spotsAvailable[1] = big;
        totalSpots[2] = spotsAvailable[2] = medium;
        totalSpots[3] = spotsAvailable[3] = small;
    }

    bool addCar(int carType) {
        if (spotsAvailable[carType] > 0) {
            spotsAvailable[carType]--;
            return true;
        }
        return false;
    }

    bool decreaseCar(int carType, int amount) {
        if (spotsAvailable[carType] + amount <= totalSpots[carType]) {
            spotsAvailable[carType] += amount;
            return true;
        }
        return false;
    }

    void viewStatus() {
        cout << "Status Parkir di " << nama << " (" << jumlahLantai << " lantai):\n";
        cout << "Big: " << spotsAvailable[1] << "/" << totalSpots[1] << endl;
        cout << "Medium: " << spotsAvailable[2] << "/" << totalSpots[2] << endl;
        cout << "Small: " << spotsAvailable[3] << "/" << totalSpots[3] << endl;
    }

    void closeParking() {
        spotsAvailable[1] = spotsAvailable[2] = spotsAvailable[3] = 0;
        cout << "Parkiran ditutup. Semua slot dikosongkan." << endl;
    }

    void showDetails() override {
        Building::showDetails();  // Call base class method
        viewStatus();
    }
};

int main() {
    ParkingSystem ps("Mall Parking", 3, 10, 20, 30);
    
    ps.showDetails();
    
    cout << "Menambahkan mobil besar..." << endl;
    ps.addCar(1);
    ps.viewStatus();
    
    cout << "Mengurangi 1 mobil besar..." << endl;
    ps.decreaseCar(1, 1);
    ps.viewStatus();
    
    cout << "Menutup parkiran..." << endl;
    ps.closeParking();
    ps.viewStatus();
    
    return 0;
}

