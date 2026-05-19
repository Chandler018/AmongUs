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

// Find height
int height(Node* root) {

    if(root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right) ? left + 1 : right + 1;
}

// Check balanced tree
bool isBalanced(Node* root) {

    if(root == NULL)
        return true;

    int left = height(root->left);
    int right = height(root->right);

    int diff = left - right;

    if(diff < 0)
        diff = -diff;

    if(diff <= 1 &&
       isBalanced(root->left) &&
       isBalanced(root->right))

        return true;

    return false;
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

    if(isBalanced(root))
        cout << "\nTree is Height Balanced";

    else
        cout << "\nTree is NOT Height Balanced";

    return 0;
}