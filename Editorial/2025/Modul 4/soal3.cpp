#include <iostream>
#include <vector>
using namespace std;

class AVLTree
{
private:
    struct AVLNode
    {
        int data;
        AVLNode *left, *right;
        int height;
        AVLNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
    };
    AVLNode *_root;
    unsigned int _size;

    int _max(int a, int b) const
    {
        return (a > b) ? a : b;
    }

    int _getHeight(AVLNode *node) const
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int _getBalanceFactor(AVLNode *node) const
    {
        if (node == nullptr)
            return 0;
        return _getHeight(node->left) - _getHeight(node->right);
    }

    AVLNode *_rightRotate(AVLNode *pivotNode)
    {
        AVLNode *newParent = pivotNode->left;
        AVLNode *T2 = newParent->right;

        newParent->right = pivotNode;
        pivotNode->left = T2;

        pivotNode->height = _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
        newParent->height = _max(_getHeight(newParent->left), _getHeight(newParent->right)) + 1;

        return newParent;
    }

    AVLNode *_leftCaseRotate(AVLNode *node)
    {
        return _rightRotate(node);
    }

    AVLNode *_leftRotate(AVLNode *pivotNode)
    {
        AVLNode *newParent = pivotNode->right;
        AVLNode *T2 = newParent->left;

        newParent->left = pivotNode;
        pivotNode->right = T2;

        pivotNode->height = _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
        newParent->height = _max(_getHeight(newParent->left), _getHeight(newParent->right)) + 1;

        return newParent;
    }

    AVLNode *_rightCaseRotate(AVLNode *node)
    {
        return _leftRotate(node);
    }

    AVLNode *_leftRightCaseRotate(AVLNode *node)
    {
        node->left = _leftRotate(node->left);
        return _rightRotate(node);
    }

    AVLNode *_rightLeftCaseRotate(AVLNode *node)
    {
        node->right = _rightRotate(node->right);
        return _leftRotate(node);
    }

    AVLNode *_createNode(int value)
    {
        return new AVLNode(value);
    }

    AVLNode *_search(AVLNode *currRoot, int value) const
    {
        while (currRoot != nullptr)
        {
            if (value < currRoot->data)
                currRoot = currRoot->left;
            else if (value > currRoot->data)
                currRoot = currRoot->right;
            else
                return currRoot;
        }
        return currRoot;
    }

    AVLNode *_insert_recursive(AVLNode *node, int value)
    {
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

        if (balanceFactor > 1 && value < node->left->data)
            return _leftCaseRotate(node);
        if (balanceFactor < -1 && value > node->right->data)
            return _rightCaseRotate(node);
        if (balanceFactor > 1 && value > node->left->data)
            return _leftRightCaseRotate(node);
        if (balanceFactor < -1 && value < node->right->data)
            return _rightLeftCaseRotate(node);

        return node;
    }

    AVLNode *_findMinNode(AVLNode *node) const
    {
        AVLNode *currNode = node;
        while (currNode && currNode->left != nullptr)
            currNode = currNode->left;
        return currNode;
    }

    AVLNode *_remove_recursive(AVLNode *node, int value)
    {
        if (node == nullptr)
            return node;

        if (value < node->data)
            node->left = _remove_recursive(node->left, value);
        else if (value > node->data)
            node->right = _remove_recursive(node->right, value);
        else
        {
            AVLNode *temp;

            if ((node->left == nullptr) || (node->right == nullptr))
            {
                temp = nullptr;
                if (node->left == nullptr)
                    temp = node->right;
                else if (node->right == nullptr)
                    temp = node->left;

                if (temp == nullptr)
                {
                    temp = node;
                    node = nullptr;
                }
                else
                {
                    *node = *temp;
                }
                free(temp);
            }
            else
            {
                temp = _findMinNode(node->right);
                node->data = temp->data;
                node->right = _remove_recursive(node->right, temp->data);
            }
        }

        if (node == nullptr)
            return node;

        node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;
        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
            return _leftCaseRotate(node);
        if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
            return _leftRightCaseRotate(node);
        if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
            return _rightCaseRotate(node);
        if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
            return _rightLeftCaseRotate(node);
        return node;
    }

    void _destroyRecursive(AVLNode *node)
    {
        if (node)
        {
            _destroyRecursive(node->left);
            _destroyRecursive(node->right);
            delete node;
        }
    }

    void _inorderRecursive(AVLNode *node, vector<int> &result) const
    {
        if (node)
        {
            _inorderRecursive(node->left, result);
            result.push_back(node->data);
            _inorderRecursive(node->right, result);
        }
    }

public:
    AVLTree() : _root(nullptr), _size(0u) {}

    ~AVLTree()
    {
        _destroyRecursive(_root);
    }

    bool find(int value) const
    {
        AVLNode *temp = _search(_root, value);
        if (temp == nullptr)
            return false;
        if (temp->data == value)
            return true;
        else
            return false;
    }

    void insert(int value)
    {
        if (!find(value))
        {
            _root = _insert_recursive(_root, value);
            _size++;
        }
    }

    void remove(int value)
    {
        if (find(value))
        {
            _root = _remove_recursive(_root, value);
            _size--;
        }
    }

    int upperBound(int value) const
    {
        AVLNode *res = nullptr;
        AVLNode *curr = _root;
        while (curr)
        {
            if (curr->data > value)
            {
                res = curr;
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        return res ? res->data : -1;
    }
};

int main()
{
    AVLTree avl;

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "i")
        {
            int x;
            cin >> x;
            avl.insert(x);
        }
        else if (cmd == "j")
        {
            int next = avl.upperBound(-1);
            if (next == -1)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << next << endl;
                avl.remove(next);
            }
        }
    }

    return 0;
}