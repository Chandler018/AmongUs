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

// Find minimum node
Node* findMin(Node* root) {

    while(root->left != NULL)
        root = root->left;

    return root;
}

// Delete node
Node* deleteNode(Node* root, int key) {

    if(root == NULL)
        return NULL;

    // Search node
    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else {

        // No child
        if(root->left == NULL &&
           root->right == NULL) {

            delete root;
            return NULL;
        }

        // One child
        else if(root->left == NULL) {

            Node* temp = root->right;
            delete root;
            return temp;
        }

        else if(root->right == NULL) {

            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Two children
        else {

            Node* temp = findMin(root->right);

            root->data = temp->data;

            root->right =
            deleteNode(root->right, temp->data);
        }
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

    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {

        cout << "Enter value: ";
        cin >> value;

        root = insert(root, value);
    }

    cout << "\nBST before deletion: ";
    inorder(root);

    cout << "\nEnter element to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "\nBST after deletion: ";
    inorder(root);

    return 0;
}