#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    int height;
};

int height(Node* n) {
    return n ? n->height : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int key, bool &rotated) {
    if (!node)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key, rotated);
    else if (key > node->key)
        node->right = insert(node->right, key, rotated);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // LL
    if (balance > 1 && key < node->left->key) {
        cout << "Rotation Performed: LL\n";
        rotated = true;
        return rightRotate(node);
    }

    // RR
    if (balance < -1 && key > node->right->key) {
        cout << "Rotation Performed: RR\n";
        rotated = true;
        return leftRotate(node);
    }

    // LR
    if (balance > 1 && key > node->left->key) {
        cout << "Rotation Performed: LR\n";
        rotated = true;
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance < -1 && key < node->right->key) {
        cout << "Rotation Performed: RL\n";
        rotated = true;
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key, bool &rotated) {
    if (!root)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key, rotated);
    else if (key > root->key)
        root->right = deleteNode(root->right, key, rotated);
    else {
        // Node with one or no child
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
        // Node with two children
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key, rotated);
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // LL
    if (balance > 1 && getBalance(root->left) >= 0) {
        cout << "Rotation Performed: LL\n";
        rotated = true;
        return rightRotate(root);
    }

    // LR
    if (balance > 1 && getBalance(root->left) < 0) {
        cout << "Rotation Performed: LR\n";
        rotated = true;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (balance < -1 && getBalance(root->right) <= 0) {
        cout << "Rotation Performed: RR\n";
        rotated = true;
        return leftRotate(root);
    }

    // RL
    if (balance < -1 && getBalance(root->right) > 0) {
        cout << "Rotation Performed: RL\n";
        rotated = true;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* search(Node* root, int key) {
    if (!root || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, key;

    do {
        cout << "\nAVL TREE MENU \n";
        cout << "1. Insert\n2. Delete\n3. Display (Inorder)\n4. Search\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            cout << "Enter value to insert: ";
            cin >> key;
            bool rotated = false;
            root = insert(root, key, rotated);
            if (!rotated)
                cout << "No rotation required\n";
            break;
        }

        case 2: {
            cout << "Enter value to delete: ";
            cin >> key;
            bool rotated = false;
            root = deleteNode(root, key, rotated);
            if (!rotated)
                cout << "No rotation required\n";
            break;
        }

        case 3:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> key;
            cout << (search(root, key) ? "Key found\n" : "Key not found\n");
            break;

        case 5:
            cout << "stopped\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
