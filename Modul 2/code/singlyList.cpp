/**
 * Implementasi ADT SInglyList (Singly Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Diubah oleh Acintya Edria Sudarsono
 * -- 7 Maret 2025
 * Struktur Data 2025
 * Implementasi untuk bahasa C++
 * 
 */

 #include <stdlib.h>
 #include <stdio.h>
 
 using namespace std;
 
 // Node structure
 struct SListNode 
 {
     int data;
     SListNode *next;
 }; 
 
 /* Struktur Singly Linked List */
 struct SinglyList
 {
     SListNode *_head;
     unsigned _size;
 
     void init() {
         _head = NULL;
         _size = 0;
     }
 
     bool isEmpty() {
         return (_head == NULL);
     }
 
     /* pushFront
        Untuk melakukan pushFront, langkah-langkahnya adalah sebagai berikut.
        1. Membuat node baru.
        2. Jika list kosong, jadikan node baru sebagai head.
        3. Jika tidak kosong, maka next dari node baru adalah head.
     */
     void pushFront(int value)
     {
         SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
         if (newNode) {
             _size++;
             newNode->data = value;
             
             if (isEmpty()) newNode->next = NULL;
             else newNode->next = _head;
             _head = newNode;
         }
     }
 
     /* pushBack
        Secara umum langkah-langkah untuk melakukan pushBack adalah sebagai berikut.
        1. Membuat node baru.
        2. Jika list kosong, maka sudah jelas bahwa head-nya adalah node baru tadi.
        3. Jika tidak kosong, telusuri hingga paling belakang,
           kemudian node paling belakang diarahkan kepada node baru.
           Penelusuran dilakukan dengan bantuan variabel temporary temp.
     */
     void pushBack(int value)
     {
         SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
         if (newNode) {
             _size++;
             newNode->data = value;
             newNode->next = NULL;
             
             if (isEmpty()) 
                 _head = newNode;
             else {
                 SListNode *temp = _head;
                 while (temp->next != NULL) 
                     temp = temp->next;
                 temp->next = newNode;
             }
         }
     }
 
     /* popFront
        Operasi popFront dapat dilakukan dengan :
        1. Tampung head pada variabel temp (temporary).
        2. Mengganti head dengan referensi/next dari head.
        3. Menghapus node temp.
     */
     void popFront()
     {
         if (!isEmpty()) {
             SListNode *temp = _head;
             _head = _head->next;
             free(temp);
             _size--;
         }
     }
 
     /* popBack
        Untuk melakukan operasi popBack, dapat dilakukan dengan:
        1. Melakukan penelusuran dengan bantuan dua node, yakni nextNode dan currNode.
        2. Jika next dari currNode kosong, maka artinya jumlah data hanya satu. Hapus langsung node tersebut.
        3. Lakukan penelusuran hingga akhir.
        4. Saat sampai akhir, hilangkan referensi dari node sekarang (currNode).
        5. Hapus node selanjutnya (nextNode).
     */
     void popBack()
     {
         if (!isEmpty()) {
             SListNode *nextNode = _head->next;
             SListNode *currNode = _head;
 
             if (currNode->next == NULL) {
                 free(currNode);
                 _head = NULL;
                 return;
             }
 
             while (nextNode->next != NULL) {
                 currNode = nextNode;
                 nextNode = nextNode->next;
             }
             currNode->next = NULL;
             free(nextNode);
             _size--;
         }
     }
 
     /* insertAt
        Operasi insertAt mempunyai proses yang cukup rumit. Terdapat beberapa kasus yang harus diperhatikan.
        Kasus 1: index 0 -> Cukup melakukan pushFront.
        Kasus 2: index berada di akhir -> Cukup melakukan pushBack.
        Kasus 3: index berada di tengah:
           1. Buat node baru.
           2. Dengan bantuan variabel temp, lakukan penelusuran hingga mencapai posisi index - 1.
           3. Arahkan next dari node baru menuju node selanjutnya dari node hasil penelusuran.
           4. Sambungkan node hasil penelusuran menuju node baru.
     */
     void insertAt(int index, int value)
     {
         if (isEmpty() || index >= _size) {
             pushBack(value);
             return;
         }
         else if (index == 0) {
             pushFront(value);
             return;
         }
 
         SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
         if (newNode) {
             SListNode *temp = _head;
             int _i = 0;
             
             while (temp->next != NULL && _i < index-1) {
                 temp = temp->next;
                 _i++;
             }
             newNode->data = value;
             newNode->next = temp->next;
             temp->next = newNode;
             _size++;
         }
     }
 
     /* front
        Manfaatkan nilai data dari head. */
     int front() {
         if (!isEmpty()) return _head->data;
         else exit(-1);
     }
 
     /* back
        Cukup dengan menelusuri hingga paling akhir dan return nilainya. */
     int back() 
     {
         if (!isEmpty()) {
             SListNode *temp = _head;
             while (temp->next != NULL)
                 temp = temp->next;
             return temp->data;
         }
         else exit(-1);
     }
 };
 
 int main(int argc, char const *argv[])
 {
     SinglyList myList;
     myList.init();
     
     myList.pushBack(2);
     myList.pushBack(3);
     myList.pushBack(4);
     myList.pushBack(5);
     myList.pushBack(6);
     
     myList.pushFront(9);
     myList.pushFront(8);
     myList.pushFront(7);
     myList.pushFront(6);
     
     for (int i = 0; i < myList._size; i++) {
         printf("%d ", myList.front());
         myList.popFront();
     }
     printf("\n");
     
     return 0;
 }