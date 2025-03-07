#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class PhoneBook {
private:
    // unordered_map menyimpan pasangan key-value (nama -> nomor telepon)
    unordered_map<string, string> contacts;
    
public:
    // Menambahkan atau memperbarui kontak
    void addContact(const string& name, const string& number) {
        contacts[name] = number; // operator[] membuat entry baru jika key belum ada
    }
    
    // Mencari nomor berdasarkan nama kontak
    string findNumber(const string& name) const {
        auto it = contacts.find(name); // find() mengembalikan iterator ke elemen jika ditemukan
        if (it != contacts.end())
            return it->second;
        else
            return "Kontak tidak ditemukan";
    }
    
    // Menghapus kontak berdasarkan nama
    void removeContact(const string& name) {
        contacts.erase(name); // erase() menghapus elemen berdasarkan key
    }
    
    // Menampilkan semua kontak
    void displayContacts() const {
        for (const auto& pair : contacts) {
            cout << "Nama: " << pair.first 
                 << ", Nomor: " << pair.second << endl;
        }
    }
};

int main() {
    PhoneBook pb;
    
    // Menambah kontak
    pb.addContact("Alice", "081234567890");
    pb.addContact("Bob", "089876543210");
    
    // Mencari kontak
    cout << "Nomor Alice: " << pb.findNumber("Alice") << endl;
    
    // Menampilkan semua kontak
    cout << "\nDaftar Kontak:" << endl;
    pb.displayContacts();
    
    // Menghapus kontak
    pb.removeContact("Bob");
    cout << "\nSetelah menghapus Bob:" << endl;
    pb.displayContacts();
    
    return 0;
}
