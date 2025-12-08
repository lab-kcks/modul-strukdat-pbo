#include <iostream>
using namespace std;


const int MAX_KARYAWAN = 100; // Batas maksimal jumlah karyawan


// Class & Object
class Karyawan
{
protected:
   string nama;
   int id;


public:
   // Constructor
   Karyawan() : nama(""), id(-1) {}
   Karyawan(string nama, int id) : nama(nama), id(id) {}


   // Setter & Getter
   void setNama(string namaBaru) { nama = namaBaru; }
   string getNama() { return nama; }
   int getId() { return id; }


   // Method/Behavior
   void display()
   {
       if (id != -1)
       {
           cout << "ID: " << id << " | Nama: " << nama << endl;
       }
   }
};


// Inheritance
class Kasir : public Karyawan
{
public:
   Kasir(string nama, int id) : Karyawan(nama, id) {}
};


class Sales : public Karyawan
{
public:
   Sales(string nama, int id) : Karyawan(nama, id) {}
};


Karyawan daftarKaryawan[MAX_KARYAWAN]; // Array statis untuk menyimpan karyawan
int jumlahKaryawan = 0;                // Menyimpan jumlah karyawan saat ini


// CRUD Operations
void tambahKaryawan()
{
   if (jumlahKaryawan >= MAX_KARYAWAN)
   {
       cout << "Kapasitas karyawan penuh!\n";
       return;
   }
   string nama;
   int id;
   cout << "Masukkan ID Karyawan: ";
   while (!(cin >> id))
   {
       cout << "Harap masukkan angka: ";
       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }
   cout << "Masukkan Nama Karyawan: ";
   cin.ignore();
   getline(cin, nama);


   daftarKaryawan[jumlahKaryawan] = Karyawan(nama, id);
   jumlahKaryawan++;
   cout << "Karyawan berhasil ditambahkan!\n";
}


void listKaryawan()
{
   if (jumlahKaryawan == 0)
   {
       cout << "Belum ada karyawan.\n";
       return;
   }
   cout << "\nData Karyawan:\n";
   for (int i = 0; i < jumlahKaryawan; i++)
   {
       daftarKaryawan[i].display();
   }
}


void editKaryawan()
{
   int id;
   cout << "Masukkan ID Karyawan yang ingin diedit: ";
   cin >> id;
   for (int i = 0; i < jumlahKaryawan; i++)
   {
       if (daftarKaryawan[i].getId() == id)
       {
           string namaBaru;
           cout << "Masukkan Nama Baru: ";
           cin.ignore();
           getline(cin, namaBaru);
           daftarKaryawan[i].setNama(namaBaru);
           cout << "Data Karyawan berhasil diperbarui!\n";
           return;
       }
   }
   cout << "Karyawan tidak ditemukan.\n";
}


void hapusKaryawan()
{
   int id;
   cout << "Masukkan ID Karyawan yang ingin dihapus: ";
   cin >> id;
   for (int i = 0; i < jumlahKaryawan; i++)
   {
       if (daftarKaryawan[i].getId() == id)
       {
           for (int j = i; j < jumlahKaryawan - 1; j++)
           {
               daftarKaryawan[j] = daftarKaryawan[j + 1];
           }
           jumlahKaryawan--;
           cout << "Karyawan berhasil dihapus!\n";
           return;
       }
   }
   cout << "Karyawan tidak ditemukan.\n";
}


void menu()
{
   cout << "\n--- Sistem Manajemen Toko Sepatu ---\n";
   cout << "1. Menambah Jumlah Karyawan\n";
   cout << "2. List Data Karyawan\n";
   cout << "3. Edit Data Karyawan\n";
   cout << "4. Menghapus Karyawan\n";
   cout << "5. Exit\n";
}


int main()
{
   while (true)
   {
       menu();
       int option;
       cout << "Masukkan Pilihan: ";
       cin >> option;


       switch (option)
       {
       case 1:
           system("clear");
           tambahKaryawan();
           break;
       case 2:
           system("clear");
           listKaryawan();
           break;
       case 3:
           system("clear");
           listKaryawan();
           editKaryawan();
           break;
       case 4:
           system("clear");
           listKaryawan();
           hapusKaryawan();
           break;
       case 5:
           cout << "Terima kasih!\n";
           return 0;
       default:
           cout << "Pilihan tidak valid!\n";
       }
   }
}
