**Definisi Overriding?**

Overriding adalah sebuah method dari superclass (kelas induk) yang ditulis kembali pada subclass (kelas anak). Karena sering kali terdapat sebuah method dari superclass (kelas induk) yang aksi pada methodnya tidak sesuai jika diterapkan pada subclass (kelas anak).

Terdapat beberapa aturan agar bisa disebut overriding:
* Parameter pada method overriding di subclass (kelas anak) harus sama dengan parameter dan return yang terdapat pada superclass (kelas induk) termasuk urutan dan banyak parameter (jika mempunyai parameter) begitupun dengan tipe data return (jika return method).
* Aturan hak akses pada fungsi overriding di subclass tidak boleh lebih ketat di bandingkan dengan hak akses method atau fungsi pada class induk.

Dengan arti bahwa overriding method membuat ulang method tertentu yang sama dengan method yang terdapat pada superclass (kelas induk) menjadi versi baru yang menyesuaikan kebutuhan subclass (kelas anak)


**Analogi Overriding**

![image](https://github.com/lab-kcks/Modul-STRUKDAT/assets/143340695/e65bc312-7bc3-4d2d-ab78-fe861bb994ca)

Dalam analogi overriding ini, bayangkan Anda memiliki sebuah kelas mobil yang telah diturunkan dari kelas induk, misalnya "Mobil". Kemudian, Anda ingin membuat kelas baru yang spesifik untuk mobil sport, misalnya "MobilSport", yang memiliki beberapa fitur tambahan, seperti Turbo.

Sekarang, Anda ingin mencetak data mobil dalam kelas "MobilSport", tetapi Anda juga ingin mencakup informasi tambahan tentang fitur Turbo. Namun, metode cetak data mobil yang ada di kelas "Mobil" hanya mencetak warna cat, jenis mobil, dan tipe transmisi. Ini tidak mencakup informasi tentang Turbo.

Untuk mengatasi ini, Anda menggunakan overriding. Anda membuat ulang metode cetak data mobil dalam kelas "MobilSport", tetapi kali ini Anda memperbarui aksinya agar mencakup informasi tentang Turbo. Misalnya, Anda menambahkan baris untuk mencetak status Turbo.



**Kelas Mobil dengan Metode Virtual**
```
class Mobil {
protected:
    string warna;
    string jenis;
    string transmisi;
public:
    Mobil(string _warna, string _jenis, string _transmisi)
        : warna(_warna), jenis(_jenis), transmisi(_transmisi) {}
    virtual void cetakDataMobil() {
        cout << "Warna: " << warna << endl;
        cout << "Jenis: " << jenis << endl;
        cout << "Transmisi: " << transmisi << endl;
    }
};
```
Metode Virtual: Metode cetakDataMobil() didefinisikan sebagai virtual. Ini penting karena memungkinkan metode ini di-override di kelas turunan.



**Kelas MobilSport Meng-override Metode cetakDataMobil**
```
class MobilSport : public Mobil {
private:
    int banyakBan;
    bool statusTurbo;
public:
    MobilSport(string _warna, string _jenis, string _transmisi, int _banyakBan, bool _statusTurbo)
        : Mobil(_warna, _jenis, _transmisi), banyakBan(_banyakBan), statusTurbo(_statusTurbo) {}
    void cetakDataMobil() override {
        Mobil::cetakDataMobil();
        cout << "Banyak Ban: " << banyakBan << endl;
        cout << "Status Turbo: " << (statusTurbo ? "Aktif" : "Tidak Aktif") << endl;
    }
};
```
* Override: Metode cetakDataMobil() di kelas MobilSport menggantikan metode dengan nama yang sama di kelas Mobil.
* Memanggil Metode Kelas Induk: Mobil::cetakDataMobil() dipanggil terlebih dahulu untuk mencetak atribut yang diwarisi dari kelas Mobil (warna, jenis, transmisi).
* Penambahan Fitur: Setelah memanggil metode kelas induk, metode cetakDataMobil() di MobilSport menambahkan logika untuk mencetak atribut tambahan (banyakBan dan statusTurbo).



**Overriding di Fungsi main**
```
int main() {
    MobilSport objSportUdin("Merah", "Sport", "Manual", 4, true);
    objSportUdin.cetakDataMobil();
    return 0;
}
```
* Instansiasi Objek: objSportUdin adalah objek dari kelas MobilSport.
* Pemanggilan Metode: Ketika objSportUdin.cetakDataMobil() dipanggil, metode cetakDataMobil() yang didefinisikan di MobilSport yang dijalankan, bukan metode cetakDataMobil() di Mobil. Hal ini karena metode tersebut di-override di MobilSport.