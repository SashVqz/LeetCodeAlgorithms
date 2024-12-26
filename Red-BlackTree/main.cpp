#include <iostream>
#include <algorithm>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Color color;
    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr), color(RED) {}
};

void leftRotate(Node*& root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    
    if (y->left != nullptr) {
        y->left->parent = x;
    }
    
    y->parent = x->parent;
    
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    
    y->left = x;
    x->parent = y;
}

void rightRotate(Node*& root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    
    if (x->right != nullptr) {
        x->right->parent = y;
    }
    
    x->parent = y->parent;
    
    if (y->parent == nullptr) {
        root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    
    x->right = y;
    y->parent = x;
}

void insertFixup(Node*& root, Node* z) {
    while (z != root && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void insert(Node*& root, int key) {
    Node* z = new Node(key);
    Node* y = nullptr;
    Node* x = root;

    while (x != nullptr) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == nullptr) {
        root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }

    z->left = nullptr;
    z->right = nullptr;
    z->color = RED;

    insertFixup(root, z);
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 15);
    insert(root, 25);
    
    cout << "Inorder traversal of the Red-Black Tree: ";
    inorder(root);
    cout << endl;

    return 0;
}