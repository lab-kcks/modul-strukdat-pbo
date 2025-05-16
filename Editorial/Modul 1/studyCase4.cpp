#include <iostream>
#include <string>
using namespace std;

// Base Class: Hero
class Hero {
protected:
    string name;
    int hp;
    int str;
    int intel;
    int cha;
    int gold;
    bool hasPotion;

public:
    // Constructor default
    Hero() : hp(0), str(0), intel(0), cha(0), gold(0), hasPotion(false) {}


    // Method to register the hero
    void registerHero() {
        cout << "Masukkan nama hero: ";
        getline(cin, name);

        int availablePoints = 10;
        int points;

        cout << "\nDistribusikan 10 stat point ke empat atribut: HP, STR, INT, CHA.\n";

        // Input untuk HP
        cout << "Tersisa " << availablePoints << " point. Masukkan point untuk HP: ";
        cin >> points;
        while (points < 0 || points > availablePoints) {
            cout << "Point tidak valid. Masukkan point untuk HP (0 - " << availablePoints << "): ";
            cin >> points;
        }
        hp = points;
        availablePoints -= points;

        // Input untuk STR
        cout << "Tersisa " << availablePoints << " point. Masukkan point untuk STR: ";
        cin >> points;
        while (points < 0 || points > availablePoints) {
            cout << "Point tidak valid. Masukkan point untuk STR (0 - " << availablePoints << "): ";
            cin >> points;
        }
        str = points;
        availablePoints -= points;

        // Input untuk INT
        cout << "Tersisa " << availablePoints << " point. Masukkan point untuk INT: ";
        cin >> points;
        while (points < 0 || points > availablePoints) {
            cout << "Point tidak valid. Masukkan point untuk INT (0 - " << availablePoints << "): ";
            cin >> points;
        }
        intel = points;
        availablePoints -= points;

        // Input untuk CHA
        cout << "Tersisa " << availablePoints << " point. Masukkan point untuk CHA: ";
        cin >> points;
        while (points < 0 || points > availablePoints) {
            cout << "Point tidak valid. Masukkan point untuk CHA (0 - " << availablePoints << "): ";
            cin >> points;
        }
        cha = points;
        availablePoints -= points;

        // Set gold awal (default 0)
        gold = 0;
        cin.ignore(); // membersihkan newline

        cout << "\nHero berhasil dibuat!\n";
        printStats();
    }

    // Virtual method to print stats (can be overridden)
    virtual void printStats() {
        cout << "\nStatus Hero:\n";
        cout << "Nama  : " << name << "\n";
        cout << "HP    : " << hp << "\n";
        cout << "STR   : " << str << "\n";
        cout << "INT   : " << intel << "\n";
        cout << "CHA   : " << cha << "\n";
        cout << "Gold  : " << gold << "\n";
        cout << "Potion: " << (hasPotion ? "Ada" : "Tidak Ada") << "\n";
    }
};

// Derived Class: HeroActivity
class HeroActivity : public Hero {
public:
    // Overridden printStats method
    void printStats() override {
        Hero::printStats(); // Call base class method
        cout << "[Activity Log: Hero's current stats displayed.]\n";
    }

    // Activity: Latihan Otot
    void latihanOtot() {
        str += 2;
        cout << "\nLatihan otot berhasil. STR naik +2.\n";
    }

    // Activity: Belajar
    void belajar() {
        intel += 2;
        cout << "\nBelajar berhasil. INT naik +2.\n";
    }

    // Activity: Tidoo
    void tidoo() {
        hp += 2;
        cout << "\nTidoo berhasil. HP naik +2.\n";
    }

    // Activity: Mewing
    void mewing() {
        cha += 2;
        cout << "\nMewing berhasil. CHA naik +2.\n";
    }

    // Activity: Fight Enemies
    void fightEnemies() {
        hp -= 3;
        gold += 10;
        cout << "\nFight enemies: HP turun 3 dan Gold naik 10.\n";
    }

    // Activity: Buy Potion
    void buyPotion() {
        if (gold < 20) {
            cout << "\nGold tidak cukup. Kamu memiliki " << gold << " Gold.\n";
        } else {
            gold -= 20;
            hasPotion = true;
            cout << "\nPotion 'lulus modul 1 strukdat' berhasil dibeli. Gold berkurang 20.\n";
        }
    }

    // Activity: Use Potion
    bool usePotion() {
        if (hasPotion) {
            hasPotion = false;
            cout << "\nCongrats\n";
            return true;
        } else {
            cout << "\nPotion belum dibeli. Silahkan beli potion terlebih dahulu.\n";
            return false;
        }
    }
};

int main() {
    HeroActivity hero;
    hero.registerHero();

    int choice;
    bool exitLoop = false;
    while (!exitLoop) {
        cout << "\nPilih aktivitas untuk hero:\n";
        cout << "1. Latihan otot\n";
        cout << "2. Belajar\n";
        cout << "3. Tidoo\n";
        cout << "4. Mewing\n";
        cout << "5. Fight enemies\n";
        cout << "6. Beli Potion 'lulus modul 1 strukdat'\n";
        cout << "7. Use potion\n";
        cout << "8. Tampilkan status hero\n";
        cout << "9. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: hero.latihanOtot(); break;
            case 2: hero.belajar(); break;
            case 3: hero.tidoo(); break;
            case 4: hero.mewing(); break;
            case 5: hero.fightEnemies(); break;
            case 6: hero.buyPotion(); break;
            case 7: if (hero.usePotion()) exitLoop = true; break;
            case 8: hero.printStats(); break;
            case 9: exitLoop = true; break;
            default: cout << "\nPilihan tidak valid. Silahkan coba lagi.\n";
        }
    }
    return 0;
}
