#include <iostream>

using namespace std;

// kelas untuk node pada BST
class BSTNode {
public:
    int key;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

// kelas Binary Search Tree
class BST {
private:
    BSTNode *root;

    // fungsi rekursif untuk menyisipkan node
    BSTNode* insert(BSTNode *node, int value) {
        if (!node)
            return new BSTNode(value);

        if (value < node->key)
            node ->left = insert(node ->left, value);
        else
            node ->right = insert(node ->right, value);

        return node;
    }

    // fungsi rekursif untuk preorder traversal
    void preorder(BSTNode *node) {
        if (node) {
            cout << node ->key << " ";
            preorder(node ->left);
            preorder(node ->right);
        }
    }

    // fungsi rekursif untuk inorder traversal
    void inorder(BSTNode *node) {
        if (node) {
            inorder(node ->left);
            cout << node ->key << " ";
            inorder(node ->right);
        }
    }

    // fungsi rekursif untuk posstorder traversal
    void postorder(BSTNode *node) {
        if (node) {
            postorder(node ->left);
            postorder(node ->right);
            cout << node ->key << " ";
        }
    }

public:
    // constructor
    BST() : root(nullptr) {}

    // menyisipkan elemen ke dalam BST
    void insert(int value) {
        root = insert(root, value);
    }

    // traversal preorder
    void traversalPreorder() {
        preorder(root);
        cout << endl;
    }

    // traversal inorder
    void traversalInorder() {
        inorder(root);
        cout << endl;
    }

    // traversal Postorder
    void traversalPostorder() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    // menambahkan elemen ke BST
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Preorder Traversal: ";
    tree.traversalPreorder();

    cout << "Inorder Traversal: ";
    tree.traversalInorder();

    cout << "Postorder Traversal: ";
    tree.traversalPostorder();

    return 0;
}