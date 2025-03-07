Konsep "Access Modifier" atau "Visibility" adalah bagian penting dari pemrograman berorientasi objek karena membantu mengatur akses terhadap properti dan metode dari suatu kelas. Berikut adalah penjelasan lebih lanjut tentang keyword yang sering digunakan:

**Public**
- Ketika sebuah property atau method dinyatakan sebagai public, maka seluruh kode program di luar class bisa mengaksesnya, termasuk class turunan.

**Analogi public**

![img](https://github.com/lab-kcks/Modul-STRUKDAT/assets/143340695/7ebe9264-1373-44d0-b8bc-8ba86e77bbd3)

**Private**
- Ketika sebuah property atau method dinyatakan sebagai private, maka property atau method tersebut tidak bisa diakses dari luar class, termasuk juga dari class turunan. Satu-satunya yang bisa mengakses adalah kode program yang ada di dalam class itu sendiri.

**Analogi Private**

![img](https://github.com/lab-kcks/Modul-STRUKDAT/assets/143340695/f4f2834a-7c1c-4299-a477-cc7c20bc34fd)

**Protected**
- Ketika sebuah property atau method dinyatakan sebagai protected, maka property atau method tersebut tidak bisa diakses dari luar class, namun masih bisa diakses oleh class itu sendiri atau turunan class tersebut.
- Protected mirip seperti private, yakni tidak bisa diakses di luar class. Perbedaannya hanya ketika class itu di turunkan, dimana property atau method yang di-set sebagai protected masih bisa diakses oleh class turunan.

**Analogi Protected**

![img](https://github.com/lab-kcks/Modul-STRUKDAT/assets/143340695/2ee7d727-0c57-4aaf-925b-7a041040b3da)

**Definisi Kelas MyClass**
```
class MyClass {
    private:
        int privateVar;

    public:
        int publicVar;

    protected:
        int protectedVar;

    public:
        // Constructor
        MyClass() {
            privateVar = 0;
            publicVar = 0;
            protectedVar = 0;
        }

        // Method untuk mengakses privateVar
        int getPrivateVar() {
            return privateVar;
        }

        // Method untuk mengatur privateVar
        void setPrivateVar(int val) {
            privateVar = val;
        }
};
```

**Fungsi Utama (main)**
```
int main() {
    MyClass obj;
    
    // Mengakses dan mengubah nilai properti publik
    obj.publicVar = 10;
    cout << "Public Var: " << obj.publicVar << endl;

    // Tidak dapat mengakses properti private atau protected
    // obj.privateVar = 20;  // Error: Tidak dapat mengakses properti private dari luar kelas
    // obj.protectedVar = 30;  // Error: Tidak dapat mengakses properti protected dari luar kelas

    // Mengakses properti private melalui method
    obj.setPrivateVar(20);
    cout << "Private Var: " << obj.getPrivateVar() << endl;

    return 0;
}
```