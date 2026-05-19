#include <iostream>
using namespace std;

// BST Node
struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Insert node
Node* insert(Node* root, int value) {

    if(root == NULL)
        return new Node(value);

    if(value < root->data)
        root->left = insert(root->left, value);

    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search element
void search(Node* root, int key) {

    if(root == NULL) {

        cout << "Element not found";
        return;
    }

    if(root->data == key) {

        cout << "Element found";
        return;
    }

    if(key < root->data)
        search(root->left, key);

    else
        search(root->right, key);
}

int main() {

    Node* root = NULL;

    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {

        cout << "Enter value: ";
        cin >> value;

        root = insert(root, value);
    }

    cout << "\nEnter element to search: ";
    cin >> key;

    search(root, key);

    return 0;
}