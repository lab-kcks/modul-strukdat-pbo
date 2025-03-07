Class adalah sebuah tipe data yang terdiri dari satu atau lebih data dan satu atau lebih fungsi. Sebuah class dapat diakses ketika class tersebut dipanggil dan dibuat dalam bentuk instance dari class tersebut.

Object adalah instance dari suatu class. Saat sebuah object dibuat, memory baru akan dialokasikan. Untuk setiap object, memiliki atribut, sifat, dan perilaku.

![image](https://github.com/lab-kcks/Modul-STRUKDAT/assets/115382618/9d9ee764-5109-44a3-9e21-7501a8baffee)
> Sumber Gambar: https://images.shiksha.com/mediadata/ugcDocuments/images/wordpressImages/2023_01_MicrosoftTeams-image-10.jpg

```cpp
// ini adalah contoh class Cat
class Cat { 
private:
  string breed;
  string color;
  int age;

public:
  Cat(string breed, string color, int age) {
    this->breed = breed;
    this->color = color;
    this->age = age;
  }

  void sound() {
    cout << "Meow" << endl;
  }

  void eat() {
    cout << "Eating fish" << endl;
  }
};

int main() {
  // Ini adalah inisiasi object dari class Cat
  Cat myCat("Persian", "White", 3); 

  myCat.sound();
  myCat.eat();

  return 0;
}
```