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

// Inorder Traversal
void inorder(Node* root) {

    if(root != NULL) {

        inorder(root->left);

        cout << root->data << " ";

        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(Node* root) {

    if(root != NULL) {

        cout << root->data << " ";

        preorder(root->left);

        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(Node* root) {

    if(root != NULL) {

        postorder(root->left);

        postorder(root->right);

        cout << root->data << " ";
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

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}