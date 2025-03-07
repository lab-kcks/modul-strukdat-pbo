Attribute/Property adalah anggota variabel data yang berada dalam sebuah class yang mewakili suatu fitur tertentu. Attribute/Property juga dapat disebut sebagai karakteristik class yang dapat diakses dari object lain atau membedakan suatu class dengan class lainnya.

Method/Behavior adalah fungsi yang terdapat dalam sebuah class. Method/Behavior dapat menggunakan suatu parameter dan menerima argumen yang nantinya dapat dimanipulasi untuk menghasilkan sebuah output sesuai tujuan dibuatnya Method/Behavior tersebut. 

```cpp
class Cat { 
private:
  string breed; // ini adalah attribute/property breed yang berada di class Cat
  string color; // ini adalah attribute/property color yang berada di class Cat
  int age; // ini adalah attribute/property age yang berada di class Cat

public:
  Cat(string breed, string color, int age) {
    this->breed = breed;
    this->color = color;
    this->age = age;
  }

  // ini adalah Method sound yang berada di dalam class Cat
  void sound() {
    cout << "Meow" << endl;
  }

  // ini adalah Method eat yang berada di dalam class Cat
  void eat() {
    cout << "Eating fish" << endl;
  }
};

int main() {
  Cat myCat("Persian", "White", 3); 

  myCat.sound(); // ini adalah pemanggilan Method sound dalam class Cat melalui object myCat
  myCat.eat(); // ini adalah pemanggilan Method eat dalam class Cat melalui object myCat

  return 0;
}
```