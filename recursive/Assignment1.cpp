#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

struct BTNode {
    int data;
    BTNode* left;
    BTNode* right;
    BTNode(int x) : data(x), left(NULL), right(NULL) {}
};

BTNode* insertBT(BTNode* root, int key) {
    if (!root) return new BTNode(key);

    queue<BTNode*> q;
    q.push(root);

    while (!q.empty()) {
        BTNode* temp = q.front(); 
        q.pop();

        if (!temp->left) {
            temp->left = new BTNode(key);
            break;
        } else q.push(temp->left);

        if (!temp->right) {
            temp->right = new BTNode(key);
            break;
        } else q.push(temp->right);
    }
    return root;
}

BTNode* copyBT(BTNode* root) {
    if (!root) return NULL;
    BTNode* newRoot = new BTNode(root->data);
    newRoot->left = copyBT(root->left);
    newRoot->right = copyBT(root->right);
    return newRoot;
}

int depthBT(BTNode* root) {
    if (!root) return 0;
    return 1 + max(depthBT(root->left), depthBT(root->right));
}

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int x) : data(x), left(NULL), right(NULL) {}
};

BSTNode* insertBST(BSTNode* root, int key) {
    if (!root) return new BSTNode(key);
    if (key < root->data)
        root->left = insertBST(root->left, key);
    else
        root->right = insertBST(root->right, key);
    return root;
}

BSTNode* minValueBST(BSTNode* node) {
    BSTNode* curr = node;
    while (curr && curr->left)
        curr = curr->left;
    return curr;
}

BSTNode* deleteBST(BSTNode* root, int key) {
    if (!root) return root;

    if (key < root->data)
        root->left = deleteBST(root->left, key);
    else if (key > root->data)
        root->right = deleteBST(root->right, key);
    else {
        //zero or one child
        if (!root->left) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }
        //two children
        BSTNode* temp = minValueBST(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

void bfsBST(BSTNode* root) {
    if (!root) return;
    queue<BSTNode*> q;
    q.push(root);

    while (!q.empty()) {
        BSTNode* curr = q.front(); q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

template <typename T>
void inorderRec(T* root) {
    if (!root) return;
    inorderRec(root->left);
    cout << root->data << " ";
    inorderRec(root->right);
}

template <typename T>
void preorderRec(T* root) {
    if (!root) return;
    cout << root->data << " ";
    preorderRec(root->left);
    preorderRec(root->right);
}

template <typename T>
void postorderRec(T* root) {
    if (!root) return;
    postorderRec(root->left);
    postorderRec(root->right);
    cout << root->data << " ";
}

template <typename T>
void inorderIter(T* root) {
    stack<T*> st;
    T* curr = root;
    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

template <typename T>
int height(T* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

template <typename T>
bool isBalanced(T* root) {
    if (!root) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return abs(lh - rh) <= 1 &&
           isBalanced(root->left) &&
           isBalanced(root->right);
}

int main() {

    int n;
    cout << "Enter number of BST nodes: ";
    cin >> n;

    BSTNode* bstRoot = NULL;
    cout << "Enter BST keys: ";
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        bstRoot = insertBST(bstRoot, x);
    }

    cout << "\nBST Traversals:\n";
    cout << "Inorder: "; inorderRec(bstRoot); cout << endl;
    cout << "Preorder: "; preorderRec(bstRoot); cout << endl;
    cout << "Postorder: "; postorderRec(bstRoot); cout << endl;
    cout << "Iterative Inorder: "; inorderIter(bstRoot); cout << endl;
    cout << "BFS (Level Order): "; bfsBST(bstRoot); cout << endl;

    cout << "\nEnter value to delete from BST: ";
    int del; cin >> del;
    bstRoot = deleteBST(bstRoot, del);
    cout << "BST after deletion (Inorder): ";
    inorderRec(bstRoot); cout << endl;

    cout << "\nEnter number of Binary Tree nodes: ";
    cin >> n;

    BTNode* btRoot = NULL;
    cout << "Enter Binary Tree values: ";
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        btRoot = insertBT(btRoot, x);
    }

    cout << "\nBinary Tree Traversals:\n";
    cout << "Inorder: "; inorderRec(btRoot); cout << endl;
    cout << "Preorder: "; preorderRec(btRoot); cout << endl;
    cout << "Postorder: "; postorderRec(btRoot); cout << endl;
    cout << "Iterative Inorder: "; inorderIter(btRoot); cout << endl;

    cout << "Depth of Binary Tree: " << depthBT(btRoot) << endl;

    BTNode* copyRoot = copyBT(btRoot);
    cout << "Inorder of Copied Binary Tree: ";
    inorderRec(copyRoot); cout << endl;

    return 0;
}
