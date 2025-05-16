#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

class AVLTree {
private:
    // Representasi Node (sebagai struct internal)
    struct AVLNode {
        int data;
        AVLNode *left, *right;
        int height;

        // Konstruktor untuk AVLNode
        AVLNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
    };

    AVLNode *_root;
    unsigned int _size;

    // Utility function: _max (seperti yang diimplikasikan di kode C Anda)
    int _max(int a, int b) const {
        return (a > b) ? a : b;
    }

    // getHeight
    int _getHeight(AVLNode* node) const {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // balance factor
    int _getBalanceFactor(AVLNode* node) const {
        if (node == nullptr)
            return 0;
        return _getHeight(node->left) - _getHeight(node->right);
    }

    // Rotasi Kanan (Case Left-Skewed)
    AVLNode* _rightRotate(AVLNode* pivotNode) {
        AVLNode* newParent = pivotNode->left;
        AVLNode* T2 = newParent->right; 

        // Lakukan rotasi
        newParent->right = pivotNode;
        pivotNode->left = T2;

        // Update tinggi
        pivotNode->height = _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
        newParent->height = _max(_getHeight(newParent->left), _getHeight(newParent->right)) + 1;

        return newParent;
    }

    // Left Case Rotate (Alias untuk _rightRotate)
    AVLNode* _leftCaseRotate(AVLNode* node) {
        return _rightRotate(node);
    }

    // Rotasi Kiri (Case Right-Skewed)
    AVLNode* _leftRotate(AVLNode* pivotNode) {
        AVLNode* newParent = pivotNode->right;
        AVLNode* T2 = newParent->left;
        // Lakukan rotasi
        newParent->left = pivotNode;
        pivotNode->right = T2;
        
        // Update tinggi
        pivotNode->height = _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
        newParent->height = _max(_getHeight(newParent->left), _getHeight(newParent->right)) + 1;

        return newParent;
    }

    // Right Case Rotate (Alias untuk _leftRotate)
    AVLNode* _rightCaseRotate(AVLNode* node) {
        return _leftRotate(node);
    }

    // Case Left-Right Zig-zag
    AVLNode* _leftRightCaseRotate(AVLNode* node) {
        node->left = _leftRotate(node->left);
        return _rightRotate(node);
    }

    // Case Right-Left Zig-zag
    AVLNode* _rightLeftCaseRotate(AVLNode* node) {
        node->right = _rightRotate(node->right);
        return _leftRotate(node);
    }

    // Create Node (utility) - menggunakan konstruktor AVLNode
    AVLNode* _createNode(int value) {
        return new AVLNode(value);
    }

    // Search (utility)
    AVLNode* _search(AVLNode *currRoot, int value) const {
        while (currRoot != nullptr) {
            if (value < currRoot->data)
                currRoot = currRoot->left;
            else if (value > currRoot->data)
                currRoot = currRoot->right;
            else
                return currRoot;
        }
        return currRoot;
    }

    // Insert (utility)
    // Parameter AVL *avl dihilangkan karena _root dan _size adalah member class
    AVLNode* _insert_recursive(AVLNode* node, int value) {
        if (node == nullptr)
            return _createNode(value);

        if (value < node->data)
            node->left = _insert_recursive(node->left, value);
        else if (value > node->data)
            node->right = _insert_recursive(node->right, value);
        else 
            return node; 


        node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));
        int balanceFactor = _getBalanceFactor(node);

        // Left Left Case
        if (balanceFactor > 1 && value < node->left->data)
            return _leftCaseRotate(node);
        // Right Right Case
        if (balanceFactor < -1 && value > node->right->data)
            return _rightCaseRotate(node);
        // Left Right Case
        if (balanceFactor > 1 && value > node->left->data)
            return _leftRightCaseRotate(node);
        // Right Left Case
        if (balanceFactor < -1 && value < node->right->data)
            return _rightLeftCaseRotate(node);
        
        return node;
    }

    // Find Min Node (utility)
    AVLNode* _findMinNode(AVLNode *node) const {
        AVLNode *currNode = node;
        while (currNode && currNode->left != nullptr)
            currNode = currNode->left;
        return currNode;
    }

    // Delete (utility)
    AVLNode* _remove_recursive(AVLNode* node, int value) {
        if (node == nullptr)
            return node;

        if (value < node->data)
            node->left = _remove_recursive(node->left, value);
        else if (value > node->data)
            node->right = _remove_recursive(node->right, value);
        else { // Node ditemukan
            AVLNode *temp;
            // Kasus dengan satu anak atau tanpa anak
            if ((node->left == nullptr) || (node->right == nullptr)) {
                temp=nullptr;
                if(node->left==nullptr) 
                    temp=node->right;  
                else if(node->right==nullptr) 
                    temp=node->left;

                if (temp == nullptr) { // Tidak ada anak
                    temp=node;
                    node=nullptr; // node saat ini akan menjadi null
                } else { // Satu anak
                    *node = *temp; 
                }
                free(temp);
            } else {
                // Kasus dengan dua anak
                temp = _findMinNode(node->right);
                node->data = temp->data;
                node->right = _remove_recursive(node->right, temp->data);
            }
        }

        if (node == nullptr) return node; // Jika tree menjadi kosong setelah penghapusan

        node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;
        int balanceFactor = _getBalanceFactor(node);

        // Left Left Case (atau Left Neutral)
        if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
            return _leftCaseRotate(node);
        // Left Right Case
        if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
            return _leftRightCaseRotate(node);
        // Right Right Case (atau Right Neutral)
        if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
            return _rightCaseRotate(node);
        // Right Left Case
        if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
            return _rightLeftCaseRotate(node);

        return node;
    }

    // Untuk destructor: menghapus semua node
    void _destroyRecursive(AVLNode* node) {
        if (node) {
            _destroyRecursive(node->left);
            _destroyRecursive(node->right);
            delete node;
        }
    }

    // Untuk traversal (contoh: inorder)
    void _inorderRecursive(AVLNode* node, vector<int>& result) const {
        if (node) {
            _inorderRecursive(node->left, result);
            result.push_back(node->data);
            _inorderRecursive(node->right, result);
        }
    }


public:
    // Inisialisasi (Konstruktor)
    AVLTree() : _root(nullptr), _size(0u) {}

    // Destruktor untuk membersihkan memori
    ~AVLTree() {
        _destroyRecursive(_root);
    }

    // Find (utama)
    bool find(int value) const {
        AVLNode *temp = _search(_root, value);
        if (temp == nullptr)
            return false;
        // Sebenarnya _search sudah memastikan temp->data == value jika temp != nullptr
        // tapi untuk konsistensi dengan kode C Anda:
        if (temp->data == value) 
            return true;
        else // Ini seharusnya tidak pernah tercapai jika _search bekerja dengan benar
            return false; 
    }

    // Insert (utama)
    void insert(int value) {
        if (!find(value)) { // Hanya insert jika belum ada
            _root = _insert_recursive(_root, value);
            _size++;
        }
    }

    // Delete (utama)
    void remove(int value) {
        if (find(value)) { // Hanya remove jika ada
            _root = _remove_recursive(_root, value);
            _size--;
        }
    }

    // Fungsi tambahan untuk mendapatkan ukuran tree
    unsigned int getSize() const {
        return _size;
    }

    // Fungsi tambahan untuk mengecek apakah tree kosong
    bool isEmpty() const {
        return _root == nullptr; // atau _size == 0
    }

    // Fungsi untuk mendapatkan traversal inorder (untuk pengujian)
    vector<int> inorderTraversal() const {
        vector<int> result;
        _inorderRecursive(_root, result);
        return result;
    }
};


// Contoh Penggunaan
int main() {
    AVLTree avl;

    cout << "Memasukkan nilai: 10, 20, 30, 40, 50, 25" << endl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30); // Akan menyebabkan rotasi kiri pada root (20)
    avl.insert(40); // Akan menyebabkan rotasi kiri pada 30
    avl.insert(50); // Akan menyebabkan rotasi kiri pada root (menjadi 30)
    avl.insert(25); // Akan menyebabkan rotasi kanan-kiri (Right-Left)

    cout << "Inorder traversal setelah insert: ";
    vector <int>inorder = avl.inorderTraversal();
    
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl; 
    cout << "Ukuran tree: " << avl.getSize() << endl; 
    cout << "Mencari 25: " << (avl.find(25) ? "Ditemukan" : "Tidak ditemukan") << endl;
    cout << "Mencari 100: " << (avl.find(100) ? "Ditemukan" : "Tidak ditemukan") << endl;
    cout << "Menghapus 20:" << endl;
    avl.remove(20);
    
    cout << "Inorder traversal setelah menghapus 20: ";
    inorder = avl.inorderTraversal();
    
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl; 
    cout << "Ukuran tree: " << avl.getSize() << endl;
    cout << "Menghapus 30 (root):" << endl;
    avl.remove(30);

    cout << "Inorder traversal setelah menghapus 30: ";
    inorder = avl.inorderTraversal();
    
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl; 
    cout << "Ukuran tree: " << avl.getSize() << endl; 

    return 0;
}
