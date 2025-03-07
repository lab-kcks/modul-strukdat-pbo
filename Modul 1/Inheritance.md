# Inheritance in C++
## Inheritance
Inheritance adalah suatu fitur atau proses dimana class baru dibuat dari class yang sudah ada. Kelas baru yang dibuat disebut “derived class” atau “child class” dan class yang sudah ada disebut “base class” atau “parent class”. 

Derived class diwariskan oleh base class. Artinya, derived class memperoleh properti dan karakteristik dari base class, dan bisa menambah fitur tersendiri tanpa mengubah properti dari base class.
- sub class: diwariskan dari base class
- super class: diwariskan dari sub class


## Kenapa menggunakan inheritance?
![image](https://github.com/lab-kcks/Modul-STRUKDAT/assets/121095246/c94fec93-8176-4071-a346-144efa4ec02b)
Pada gambar di atas, dapat dilihat bahwa masing-masing binatang memiliki karakteristik dan properti yang sama. Duplikasi ini dapat menyebabkan data redudancy dan meningkatkan kemungkinan error.

Untuk menghindari duplikasi code, inheritance dapat digunakan dengan membuat derived class dari base class.
![image](https://github.com/lab-kcks/Modul-STRUKDAT/assets/121095246/f636d001-ae6f-4c0e-8900-9c1f26345994)



## Implementasi
```cpp
class  <derived_class_name> : <access-specifier> <base_class_name>
{
        //body
}
```

### Contoh sederhana
```cpp
class Animal {
public:
    void eat() {
        cout << "Animal is eating" << endl;
    }

    void sleep() {
        cout << "Animal is sleeping" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking" << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "Cat is meowing" << endl;
    }
};
```
Pada program di atas class Dog dan class Cat memperoleh properti pada base class Animal.

## Jenis-jenis Inheritance
Terdapat beberapa jenis inheritance, diantaranya:
1. Single inheritance
2. Multilevel inheritance
3. Multiple inheritance
4. Hierarchical inheritance
5. Hybrid inheritance

### [1] Single Inheritance
Suatu subclass diwarisi oleh satu base class saja.

**Format**
```cpp
class subclass_name : access_mode base_class
{
  // body of subclass
};
```
```
class A
{ 
... .. ... 
};
class B: public A
{
... .. ...
};
```


### [2] Multiple Inheritance
Suatu base class mewarisi lebih dari 1 class.

**Format**
```cpp
class subclass_name : access_mode base_class1, access_mode base_class2, ....
{
  // body of subclass
};
```
```cpp
class B
{ 
... .. ... 
};
class C
{
... .. ...
};
class A: public B, public C
{
... ... ...
};
```

### [3] Multilevel Inheritance
Derived class dibuat dari derived class lain.
```cpp
class C
{ 
... .. ... 
};
class B:public C
{
... .. ...
};
class A: public B
{
... ... ...
};
```

### [4] Hierarchical Inheritance
Lebih dari satu subclass diwariskan oleh satu base class.
```cpp
class A  
{  
    // body of the class A.
}
class B : public A
{  
    // body of class B.  
}
class C : public A
{
    // body of class C.  
}
class D : public A
{  
    // body of class D.  
}
```

### [5] Hybrid Inheritance
Menggunakan campuran dari jenis-jenis inheritance yang berbeda.
![](https://media.geeksforgeeks.org/wp-content/uploads/Hybrid-Inheritance.png)
> Source: https://media.geeksforgeeks.org/wp-content/uploads/Hybrid-Inheritance.png