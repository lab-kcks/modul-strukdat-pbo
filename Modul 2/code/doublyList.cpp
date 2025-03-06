#include <iostream>
using namespace std;

// Mendefinisikan kelas bernama Node untuk merepresentasikan node dalam double linked list.
class Node {
public:
    int data;
    // Pointer ke node berikutnya.
    Node* next;
    // Pointer ke node sebelumnya.
    Node* prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Menambahkan node di awal (head) dari double linked list.
void insertAtBeginning(Node*& head, int data)
{
    // Membuat node baru dengan data yang diberikan.
    Node* newNode = new Node(data);

    // Memeriksa apakah double linked list kosong.
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Memperbarui pointer next dan prev untuk menambahkan node baru di awal.
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Menambahkan node di akhir dari double linked list.
void insertAtEnd(Node*& head, int data)
{
    // Membuat node baru dengan data yang diberikan.
    Node* newNode = new Node(data);

    // Memeriksa apakah double linked list kosong.
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Menelusuri hingga node terakhir dalam list.
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Memperbarui pointer next dan prev untuk menambahkan node baru di akhir.
    temp->next = newNode;
    newNode->prev = temp;
}

// Menambahkan node di posisi tertentu dalam double linked list.
void insertAtPosition(Node*& head, int data, int position)
{
    if (position < 1) {
        cout << "Posisi harus >= 1." << endl;
        return;
    }

    // Jika menambahkan di posisi pertama.
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    // Membuat node baru dengan data yang diberikan.
    Node* newNode = new Node(data);
    Node* temp = head;

    // Menelusuri hingga node sebelum posisi yang ditentukan.
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    // Memeriksa apakah posisi lebih besar dari jumlah node yang ada.
    if (temp == nullptr) {
        cout << "Posisi lebih besar dari jumlah node yang ada." << endl;
        return;
    }

    // Memperbarui pointer next dan prev untuk menambahkan node di posisi tertentu.
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Menghapus node dari awal double linked list.
void deleteAtBeginning(Node*& head)
{
    // Memeriksa apakah double linked list kosong.
    if (head == nullptr) {
        cout << "List sudah kosong." << endl;
        return;
    }

    // Memperbarui pointer head dan menghapus node pertama.
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

// Menghapus node dari akhir double linked list.
void deleteAtEnd(Node*& head)
{
    // Memeriksa apakah double linked list kosong.
    if (head == nullptr) {
        cout << "List sudah kosong." << endl;
        return;
    }

    Node* temp = head;
    // Jika hanya ada satu node dalam list.
    if (temp->next == nullptr) {
        head = nullptr;
        delete temp;
        return;
    }

    // Menelusuri hingga node terakhir dalam list.
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Memperbarui pointer prev dari node sebelum node terakhir dan menghapus node terakhir.
    temp->prev->next = nullptr;
    delete temp;
}

// Menghapus node dari posisi tertentu dalam double linked list.
void deleteAtPosition(Node*& head, int position)
{
    // Memeriksa apakah double linked list kosong.
    if (head == nullptr) {
        cout << "List sudah kosong." << endl;
        return;
    }

    // Jika menghapus node pertama.
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }

    Node* temp = head;
    // Menelusuri hingga node di posisi yang ditentukan.
    for (int i = 1; temp != nullptr && i < position; i++) {
        temp = temp->next;
    }

    // Memeriksa apakah posisi lebih besar dari jumlah node yang ada.
    if (temp == nullptr) {
        cout << "Posisi lebih besar dari jumlah node yang ada." << endl;
        return;
    }

    // Memperbarui pointer next dan prev, lalu menghapus node di posisi yang ditentukan.
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    delete temp;
}

// Mencetak double linked list dalam arah maju.
void printListForward(Node* head)
{
    Node* temp = head;
    cout << "Forward List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Mencetak double linked list dalam arah mundur.
void printListReverse(Node* head)
{
    Node* temp = head;
    if (temp == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

    // Bergerak ke akhir list.
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Menelusuri mundur.
    cout << "Backward List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    Node* head = nullptr;

    // Operasi pada double linked list.
    // Menambahkan node di akhir
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    // Menambahkan node di awal
    insertAtBeginning(head, 5);
    // Menambahkan node di posisi tertentu
    insertAtPosition(head, 15, 2);

    // Mencetak list setelah operasi penambahan
    cout << "Setelah Penambahan:" << endl;
    printListForward(head);
    printListReverse(head);

    // Menghapus node dari awal
    deleteAtBeginning(head);
    // Menghapus node dari akhir
    deleteAtEnd(head);
    // Menghapus node dari posisi tertentu
    deleteAtPosition(head, 2);

    cout << "Setelah Penghapusan:" << endl;
    printListForward(head);

    return 0;
}