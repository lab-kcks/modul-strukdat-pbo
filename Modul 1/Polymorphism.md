Kata “polymorphism” berarti memiliki banyak bentuk. Dengan kata sederhana, kita dapat mendefinisikan polymorphism sebagai kemampuan sebuah pesan untuk ditampilkan dalam lebih dari satu bentuk. Contoh nyata dari polymorphism adalah seseorang yang pada saat yang sama dapat memiliki karakteristik yang berbeda. Seorang pria pada saat yang sama adalah seorang ayah, suami, dan karyawan. Jadi orang yang sama menunjukkan perilaku yang berbeda dalam situasi yang berbeda. Ini disebut polymorphism. Polymorphism dianggap sebagai salah satu fitur penting dari Pemrograman Berorientasi Objek.

![image](https://github.com/lab-kcks/Modul-STRUKDAT/assets/62441217/8d48cd18-c799-4808-9512-9c9ac09299b8)
> Sumber Gambar:  
> https://media.geeksforgeeks.org/wp-content/uploads/20200703160531/Polymorphism-in-CPP.png

**Types of Polymorphism:**  
**Compile-time Polymorphism:** Jenis tipe ini dicapai dengan function overloading atau operator overloading.  
**Runtime Polymorphism:** Jenis polymorphism ini dicapai dengan Function Overriding.  

**1. Compile-time Polymorphism**  
Jenis tipe ini dicapai dengan function overloading atau operator overloading.  

**A. Function Overloading**  
Ketika ada beberapa fungsi dengan nama yang sama tetapi parameternya berbeda, maka fungsi-fungsi tersebut dikatakan overload, oleh karena itu hal ini dikenal dengan istilah Function Overloading. Fungsi dapat dibebani dengan mengubah jumlah argumen atau/dan mengubah jenis argumen. Secara sederhana, ini adalah fitur pemrograman berorientasi objek yang menyediakan banyak fungsi yang memiliki nama yang sama tetapi parameter yang berbeda ketika banyak tugas terdaftar di bawah satu nama fungsi. Ada beberapa aturan tertentu dari Function Overloading yang harus diikuti saat membebani sebuah fungsi.  

Contoh kode function overloading:  
```cpp// Fungsi untuk menambahkan dua bilangan bulat
int add(int a, int b) {
    return a + b;
}

// Fungsi untuk menambahkan tiga bilangan bulat
int add(int a, int b, int c) {
    return a + b + c;
}

// Fungsi untuk menambahkan dua bilangan desimal
double add(double a, double b) {
    return a + b;
}

// Fungsi untuk menambahkan dua string
string add(const string &a, const string &b) {
    return a + b;
}
```

**B. Operator Overloading**  
C++ memiliki kemampuan untuk menyediakan operator dengan arti khusus untuk sebuah tipe data, kemampuan ini dikenal sebagai operator overloading. Sebagai contoh, kita dapat menggunakan operator penjumlahan (+) untuk kelas string untuk menggabungkan dua buah string. Kita tahu bahwa tugas operator ini adalah menambahkan dua operand. Jadi satu operator '+', ketika ditempatkan di antara operand bilangan bulat, akan menambahkannya dan ketika ditempatkan di antara operand string, akan menggabungkannya.

Contoh kode operator overloading:  
```cpp
class Kompleks {
private:
    double real;
    double imag;

public:
    // Konstruktor
    Kompleks(double r = 0, double i = 0) : real(r), imag(i) {}

    // Operator overloading untuk operator +
    Kompleks operator+(const Kompleks& other) const {
        return Kompleks(real + other.real, imag + other.imag);
    }

    // Operator overloading untuk operator -
    Kompleks operator-(const Kompleks& other) const {
        return Kompleks(real - other.real, imag - other.imag);
    }

    // Operator overloading untuk operator <<
    friend ostream& operator<<(ostream& os, const Kompleks& k) {
        os << k.real << " + " << k.imag << "i";
        return os;
    }

    // Operator overloading untuk operator ==
    bool operator==(const Kompleks& other) const {
        return (real == other.real && imag == other.imag);
    }
};

// Fungsi untuk melakukan operasi dan mencetak hasilnya
void printOperations() {
    Kompleks k1(3.0, 4.0);
    Kompleks k2(1.0, 2.0);

    Kompleks k3 = k1 + k2;  // Menggunakan operator +
    Kompleks k4 = k1 - k2;  // Menggunakan operator -

    cout << "k1: " << k1 << endl;
    cout << "k2: " << k2 << endl;
    cout << "k1 + k2: " << k3 << endl;
    cout << "k1 - k2: " << k4 << endl;

    // Menggunakan operator ==
    if (k1 == k2) {
        cout << "k1 dan k2 adalah sama" << endl;
    } else {
        cout << "k1 dan k2 tidak sama" << endl;
    }
}
```

**2. Runtime Polymorphism**  
Jenis polymorphism ini dicapai dengan Penimpaan Fungsi. Pengikatan akhir dan polimorfisme dinamis adalah nama lain dari polymorphism runtime. Pemanggilan fungsi diselesaikan pada saat runtime dalam polymorphism runtime. Sebaliknya, dengan polymorphism waktu kompilasi, kompiler menentukan pemanggilan fungsi mana yang akan diikat ke objek setelah menyimpulkannya pada saat runtime.  

**A. Function Overriding**  
Function Overriding terjadi ketika kelas turunan memiliki definisi untuk salah satu fungsi anggota dari kelas dasar. Fungsi dasar tersebut dikatakan overriding.  

Contoh kode function overriding:
```cpp
// Kelas dasar (Base class)
class Shape {
public:
    // Fungsi virtual yang akan dioverride di kelas turunan
    virtual void draw() const {
        cout << "Drawing a shape" << endl;
    }

    // Fungsi virtual destructor
    virtual ~Shape() {}
};

// Kelas turunan (Derived class)
class Circle : public Shape {
public:
    // Mengoverride fungsi draw
    void draw() const override {
        cout << "Drawing a circle" << endl;
    }
};

// Kelas turunan (Derived class)
class Rectangle : public Shape {
public:
    // Mengoverride fungsi draw
    void draw() const override {
        cout << "Drawing a rectangle" << endl;
    }
};

// Fungsi untuk mencetak bentuk
void printShape(const Shape& shape) {
    shape.draw();
}
```

**B. Virtual Function**  
Virtual function adalah fungsi anggota yang dideklarasikan di kelas dasar menggunakan kata kunci virtual dan didefinisikan ulang (override) di kelas turunan.  

Beberapa Poin Penting Tentang Fungsi Virtual:
- Fungsi virtual bersifat dinamis.  
- Fungsi virtual didefinisikan dengan memasukkan kata kunci “virtual” di dalam kelas dasar dan selalu dideklarasikan dengan kelas dasar dan ditimpa di kelas anak.  
- Fungsi virtual dipanggil selama Runtime  

Contoh kode virtual function:  
```cpp
// Kelas dasar (Base class)
class Animal {
public:
    // Fungsi virtual
    virtual void sound() const {
        cout << "Animal makes a sound" << endl;
    }

    // Fungsi virtual destructor
    virtual ~Animal() {}
};

// Kelas turunan (Derived class)
class Dog : public Animal {
public:
    // Mengoverride fungsi sound
    void sound() const override {
        cout << "Dog barks" << endl;
    }
};

// Kelas turunan (Derived class)
class Cat : public Animal {
public:
    // Mengoverride fungsi sound
    void sound() const override {
        cout << "Cat meows" << endl;
    }
};

// Fungsi untuk mencetak suara hewan
void printSound(const Animal& animal) {
    animal.sound();
}
```