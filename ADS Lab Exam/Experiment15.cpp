#include <iostream>
using namespace std;

// AVL Node
struct Node {
    int data, height;
    Node *left, *right;

    Node(int value) {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

// Get height
int height(Node* root) {

    if(root == NULL)
        return 0;

    return root->height;
}

// Maximum function
int max(int a, int b) {

    return (a > b) ? a : b;
}

// Balance factor
int balance(Node* root) {

    if(root == NULL)
        return 0;

    return height(root->left) -
           height(root->right);
}

// Right Rotation
Node* rightRotate(Node* y) {

    Node* x = y->left;
    Node* t = x->right;

    x->right = y;
    y->left = t;

    y->height =
    max(height(y->left), height(y->right)) + 1;

    x->height =
    max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left Rotation
Node* leftRotate(Node* x) {

    Node* y = x->right;
    Node* t = y->left;

    y->left = x;
    x->right = t;

    x->height =
    max(height(x->left), height(x->right)) + 1;

    y->height =
    max(height(y->left), height(y->right)) + 1;

    return y;
}

// Insert node
Node* insert(Node* root, int value) {

    // BST insertion
    if(root == NULL)
        return new Node(value);

    if(value < root->data)
        root->left = insert(root->left, value);

    else if(value > root->data)
        root->right = insert(root->right, value);

    else
        return root;

    // Update height
    root->height =
    1 + max(height(root->left),
            height(root->right));

    // Balance factor
    int bf = balance(root);

    // LL Rotation
    if(bf > 1 && value < root->left->data)
        return rightRotate(root);

    // RR Rotation
    if(bf < -1 && value > root->right->data)
        return leftRotate(root);

    // LR Rotation
    if(bf > 1 && value > root->left->data) {

        root->left = leftRotate(root->left);

        return rightRotate(root);
    }

    // RL Rotation
    if(bf < -1 && value < root->right->data) {

        root->right = rightRotate(root->right);

        return leftRotate(root);
    }

    return root;
}

// Inorder Traversal
void inorder(Node* root) {

    if(root != NULL) {

        inorder(root->left);

        cout << root->data << " ";

        inorder(root->right);
    }
}

int main() {

    Node* root = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {

        cout << "Enter value: ";
        cin >> value;

        root = insert(root, value);
    }

    cout << "\nAVL Tree Inorder Traversal: ";

    inorder(root);

    return 0;
}