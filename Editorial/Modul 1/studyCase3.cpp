#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Base class Menu
class Menu {
protected:
    string name;
    double price;
public:
    Menu(string n = "", double p = 0.0) : name(n), price(p) {}

    void setName(string n) { name = n; }
    string getName() const { return name; }

    void setPrice(double p) { price = p; }
    double getPrice() const { return price; }

    virtual void display() const {
        cout << "Nama: " << name << " | Harga: Rp " << price << endl;
    }

    virtual ~Menu() {} // Virtual destructor for proper cleanup
};

// Derived class Food
class Food : public Menu {
private:
    string portionSize;
    string buffEffect;
public:
    Food(string n, double p, string ps, string be) : Menu(n, p), portionSize(ps), buffEffect(be) {}

    void setPortionSize(string ps) { portionSize = ps; }
    string getPortionSize() const { return portionSize; }

    void setBuffEffect(string be) { buffEffect = be; }
    string getBuffEffect() const { return buffEffect; }

    void display() const override {
        cout << "[FOOD] " << name << " | Harga: Rp " << price << " | Porsi: " << portionSize << " | Buff: " << buffEffect << endl;
    }
};

// Derived class Drink
class Drink : public Menu {
private:
    string volume;
    string sweetness;
public:
    Drink(string n, double p, string v, string s) : Menu(n, p), volume(v), sweetness(s) {}

    void setVolume(string v) { volume = v; }
    string getVolume() const { return volume; }

    void setSweetness(string s) { sweetness = s; }
    string getSweetness() const { return sweetness; }

    void display() const override {
        cout << "[DRINK] " << name << " | Harga: Rp " << price << " | Volume: " << volume << " | Manis: " << sweetness << endl;
    }
};

// CRUD Functions
void createMenu(Menu* menuList[], int& count) {
    string name, type, attr1, attr2;
    double price;
    cout << "Jenis Menu (Food/Drink): "; cin >> type;
    cin.ignore();

    if (type != "Food" && type != "food" && type != "Drink" && type != "drink") {
        cout << "Jenis menu tidak valid!" << endl;
        return;
    }

    cout << "Nama: "; getline(cin, name);
    cout << "Harga: ";
    while (!(cin >> price)) {
        cout << "Input harga tidak valid. Masukkan angka: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

    if (type == "Food" || type == "food") {
        cout << "Porsi (kecil/sedang/besar): "; getline(cin, attr1);
        if (attr1 != "kecil" && attr1 != "sedang" && attr1 != "besar") {
            cout << "Porsi tidak valid!" << endl;
            return;
        }

        cout << "Buff Effect (low/medium/high): "; getline(cin, attr2);
        if (attr2 != "low" && attr2 != "medium" && attr2 != "high") {
            cout << "Buff Effect tidak valid!" << endl;
            return;
        }

        menuList[count++] = new Food(name, price, attr1, attr2);
    } else if (type == "Drink" || type == "drink") {
        cout << "Volume (kecil/sedang/besar): "; getline(cin, attr1);
        if (attr1 != "kecil" && attr1 != "sedang" && attr1 != "besar") {
            cout << "Volume tidak valid!" << endl;
            return;
        }

        cout << "Manis (less/normal/extra): "; getline(cin, attr2);
        if (attr2 != "less" && attr2 != "normal" && attr2 != "extra") {
            cout << "Tingkat manis tidak valid!" << endl;
            return;
        }

        menuList[count++] = new Drink(name, price, attr1, attr2);
    }
}

void readMenu(Menu* menuList[], int count) {
    for (int i = 0; i < count; ++i) {
        menuList[i]->display();
    }
}

void updateMenu(Menu* menuList[], int count) {
    string searchName;
    cout << "Masukkan nama menu yang ingin diperbarui: ";
    cin.ignore();
    getline(cin, searchName);

    for (int i = 0; i < count; ++i) {
        if (menuList[i]->getName() == searchName) {
            double newPrice;
            cout << "Masukkan harga baru: ";
            while (!(cin >> newPrice)) {
                cout << "Input harga tidak valid. Masukkan angka: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            menuList[i]->setPrice(newPrice);
            cout << "Menu diperbarui dengan sukses." << endl;
            return;
        }
    }
    cout << "Menu tidak ditemukan." << endl;
}

void deleteMenu(Menu* menuList[], int& count) {
    string searchName;
    cout << "Masukkan nama menu yang ingin dihapus: ";
    cin.ignore();
    getline(cin, searchName);

    for (int i = 0; i < count; ++i) {
        if (menuList[i]->getName() == searchName) {
            delete menuList[i];
            for (int j = i; j < count - 1; ++j) {
                menuList[j] = menuList[j + 1];
            }
            count--;
            cout << "Menu berhasil dihapus." << endl;
            return;
        }
    }
    cout << "Menu tidak ditemukan." << endl;
}

int main() {
    const int MAX_MENU = 100;
    Menu* menuList[MAX_MENU];
    int count = 0;
    int choice;

    do {
        cout << "\n=== MENU CRUD ===" << endl;
        cout << "1. Tambah Menu\n2. Lihat Menu\n3. Perbarui Menu\n4. Hapus Menu\n5. Keluar" << endl;
        cout << "Pilihan: "; cin >> choice;

        switch (choice) {
            case 1: createMenu(menuList, count); break;
            case 2: readMenu(menuList, count); break;
            case 3: updateMenu(menuList, count); break;
            case 4: deleteMenu(menuList, count); break;
            case 5: cout << "Program selesai." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 5);

    for (int i = 0; i < count; ++i) {
        delete menuList[i];
    }

    return 0;
}
