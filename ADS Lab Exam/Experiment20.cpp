#include <iostream>
using namespace std;

#define MAX 3

// B-Tree Node
struct Node {
    int keys[MAX];
    Node* child[MAX + 1];
    int count;
    bool leaf;
};

// Create node
Node* createNode(bool leaf) {

    Node* temp = new Node;

    temp->leaf = leaf;
    temp->count = 0;

    for(int i = 0; i < MAX + 1; i++)
        temp->child[i] = NULL;

    return temp;
}

// Display B-Tree
void display(Node* root) {

    if(root != NULL) {

        for(int i = 0; i < root->count; i++) {

            if(!root->leaf)
                display(root->child[i]);

            cout << root->keys[i] << " ";
        }

        if(!root->leaf)
            display(root->child[root->count]);
    }
}

// Split child
void splitChild(Node* parent,
                int i,
                Node* fullChild) {

    Node* newChild =
    createNode(fullChild->leaf);

    int mid = MAX / 2;

    newChild->count = MAX - mid - 1;

    // Move keys
    for(int j = 0; j < newChild->count; j++)
        newChild->keys[j] =
        fullChild->keys[j + mid + 1];

    // Move children
    if(!fullChild->leaf) {

        for(int j = 0; j <= newChild->count; j++)
            newChild->child[j] =
            fullChild->child[j + mid + 1];
    }

    fullChild->count = mid;

    // Shift children
    for(int j = parent->count;
        j >= i + 1; j--)

        parent->child[j + 1] =
        parent->child[j];

    parent->child[i + 1] = newChild;

    // Shift keys
    for(int j = parent->count - 1;
        j >= i; j--)

        parent->keys[j + 1] =
        parent->keys[j];

    // Promote middle key
    parent->keys[i] =
    fullChild->keys[mid];

    parent->count++;

    cout << "\nNode Split! Promoted Key: "
         << fullChild->keys[mid];
}

// Insert in non-full node
void insertNonFull(Node* root, int key) {

    int i = root->count - 1;

    // Leaf node
    if(root->leaf) {

        while(i >= 0 &&
              key < root->keys[i]) {

            root->keys[i + 1] =
            root->keys[i];

            i--;
        }

        root->keys[i + 1] = key;

        root->count++;
    }

    // Internal node
    else {

        while(i >= 0 &&
              key < root->keys[i])

            i--;

        i++;

        // Split full child
        if(root->child[i]->count == MAX) {

            splitChild(root,
                       i,
                       root->child[i]);

            if(key > root->keys[i])
                i++;
        }

        insertNonFull(root->child[i], key);
    }
}

// Insert key
Node* insert(Node* root, int key) {

    // Root full
    if(root->count == MAX) {

        Node* newRoot =
        createNode(false);

        newRoot->child[0] = root;

        splitChild(newRoot, 0, root);

        insertNonFull(newRoot, key);

        return newRoot;
    }

    insertNonFull(root, key);

    return root;
}

int main() {

    Node* root = createNode(true);

    int n, key;

    cout << "Enter number of keys: ";
    cin >> n;

    for(int i = 0; i < n; i++) {

        cout << "Enter key: ";
        cin >> key;

        root = insert(root, key);
    }

    cout << "\nB-Tree Traversal: ";

    display(root);

    return 0;
}