#include <iostream>
#include <set>
#include <string>

using namespace std;

// Class untuk menyimpan data mahasiswa
class Mahasiswa {
private:
    int nim;
    string nama;
    float ipk;

public:
    // Constructor
    Mahasiswa(int _nim, string _nama, float _ipk) 
        : nim(_nim), nama(_nama), ipk(_ipk) {}
    
    // Getter methods
    int getNim() const { return nim; }
    string getNama() const { return nama; }
    float getIpk() const { return ipk; }
    
    // Untuk menampilkan informasi mahasiswa
    void printInfo() const {
        cout << "NIM: " << nim << ", Nama: " << nama << ", IPK: " << ipk << endl;
    }
    
    // Operator overloading untuk membandingkan objek (diperlukan untuk set)
    bool operator<(const Mahasiswa& other) const {
        return nim < other.nim; // Membandingkan berdasarkan NIM
    }
};

// Class untuk mengelola data mahasiswa menggunakan set
class DatabaseMahasiswa {
private:
    set<Mahasiswa> daftarMahasiswa;

public:
    // Menambahkan mahasiswa baru
    void tambahMahasiswa(const Mahasiswa& mhs) {
        auto hasil = daftarMahasiswa.insert(mhs);
        if (hasil.second) {
            cout << "Mahasiswa dengan NIM " << mhs.getNim() << " berhasil ditambahkan." << endl;
        } else {
            cout << "Mahasiswa dengan NIM " << mhs.getNim() << " sudah ada dalam database." << endl;
        }
    }
    
    // Menghapus mahasiswa berdasarkan NIM
    void hapusMahasiswa(int nim) {
        bool ditemukan = false;
        for (auto it = daftarMahasiswa.begin(); it != daftarMahasiswa.end(); ++it) {
            if (it->getNim() == nim) {
                daftarMahasiswa.erase(it);
                cout << "Mahasiswa dengan NIM " << nim << " telah dihapus." << endl;
                ditemukan = true;
                break;
            }
        }
        
        if (!ditemukan) {
            cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
        }
    }
    
    // Mencari mahasiswa berdasarkan NIM
    void cariMahasiswa(int nim) {
        bool ditemukan = false;
        for (const auto& mhs : daftarMahasiswa) {
            if (mhs.getNim() == nim) {
                cout << "Mahasiswa ditemukan: ";
                mhs.printInfo();
                ditemukan = true;
                break;
            }
        }
        
        if (!ditemukan) {
            cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
        }
    }
    
    // Menampilkan semua mahasiswa
    void tampilkanSemuaMahasiswa() const {
        if (daftarMahasiswa.empty()) {
            cout << "Database mahasiswa kosong." << endl;
            return;
        }
        
        cout << "Daftar Mahasiswa:" << endl;
        int nomor = 1;
        for (const auto& mhs : daftarMahasiswa) {
            cout << nomor++ << ". ";
            mhs.printInfo();
        }
    }
    
    // Mendapatkan jumlah mahasiswa
    size_t jumlahMahasiswa() const {
        return daftarMahasiswa.size();
    }
    
    // Mengosongkan database
    void kosongkanDatabase() {
        daftarMahasiswa.clear();
        cout << "Database mahasiswa telah dikosongkan." << endl;
    }
};

int main() {
    DatabaseMahasiswa db;
    
    // Menambahkan beberapa mahasiswa
    db.tambahMahasiswa(Mahasiswa(101, "Budi Santoso", 3.75));
    db.tambahMahasiswa(Mahasiswa(102, "Andi Wijaya", 3.50));
    db.tambahMahasiswa(Mahasiswa(103, "Siti Nurbaya", 3.90));
    db.tambahMahasiswa(Mahasiswa(101, "Duplikat Budi", 3.25)); // NIM duplikat
    
    cout << "\nJumlah mahasiswa dalam database: " << db.jumlahMahasiswa() << endl;
    
    // Menampilkan semua mahasiswa
    cout << "\n";
    db.tampilkanSemuaMahasiswa();
    
    // Mencari mahasiswa
    cout << "\n";
    db.cariMahasiswa(102);
    db.cariMahasiswa(105); // NIM tidak ada
    
    // Menghapus mahasiswa
    cout << "\n";
    db.hapusMahasiswa(103);
    
    // Menampilkan lagi setelah penghapusan
    cout << "\n";
    db.tampilkanSemuaMahasiswa();
    
    // Mengosongkan database
    cout << "\n";
    db.kosongkanDatabase();
    db.tampilkanSemuaMahasiswa();
    
    return 0;
}