#include <iostream>
using namespace std;

// Class Node
class BSTNode {
public:
    int key;
    BSTNode *left, *right;

    BSTNode(int value) {
        key = value;
        left = right = nullptr;
    }
};

// Class BST
class BST {
private:
    BSTNode* _root;
    unsigned int _size;

    // Helper function: search node
    BSTNode* __search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;

            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    // Helper function: insert node
    BSTNode* __insert(BSTNode *root, int value) {
        if (root == NULL) 
        {
            return new BSTNode(value);
        }

        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);

        return root;
    }

    // Helper function: find min node (used in remove)
    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    // Helper function: remove node
    BSTNode* __remove(BSTNode *root, int value) {
        if (root == NULL) return NULL;

        if (value < root->key)
            root->left = __remove(root->left, value);
        else if (value > root->key)
            root->right = __remove(root->right, value);
        else {
            // Node with only one child or no child
            if (root->left == NULL) 
            {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            } else if (root->right == NULL) 
            {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            // Node with two children
            BSTNode *temp = __findMinNode(root->right);
            root->key = temp->key;
            root->right = __remove(root->right, temp->key);
        }
        return root;
    }

    // Helper: traversal
    void __inorder(BSTNode* node) {
        if (node) {
            __inorder(node->left);
            cout << node->key << " ";
            __inorder(node->right);
        }
    }

public:
    // Constructor
    BST() {
        _root = nullptr;
        _size = 0;
    }

    // Destructor
    ~BST() {
        __deleteTree(_root);
    }

    void __deleteTree(BSTNode* node) {
        if (node) {
            __deleteTree(node->left);
            __deleteTree(node->right);
            delete node;
        }
    }

    // Check if tree is empty
    bool isEmpty() {
        return _root == NULL;
    }

    // Insert a value
    void insert(int value) {
        if (!find(value)) 
        {
            _root = __insert(_root, value);
            _size++;
        }
    }

    // Remove a value
    void remove(int value) {
        if (find(value)) 
        {
            _root = __remove(_root, value);
            _size--;
        }
    }

    // Find a value
    bool find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;
        if (temp->key == value)
            return true;
        else
            return false;
    }

    // Inorder traversal
    void inorder() {
        __inorder(_root);
        cout << endl;
    }

    // Get size
    unsigned int size() {
        return _size;
    }
};

int main() {
    BST tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);

    cout << "Inorder traversal: ";
    tree.inorder(); // 1 3 4 5 7

    cout << "Apakah 3 ada?" << (tree.find(3) ? "\nYa" : "\nTidak") << endl;

    tree.remove(3);
    cout << "Setelah menghapus 3: ";
    tree.inorder(); // 1 4 5 7

    cout << "Ukuran tree: " << tree.size() << endl;

    return 0;
}
