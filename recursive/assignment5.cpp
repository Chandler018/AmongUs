#include <iostream>
using namespace std;

const int ORDER = 4;              
const int MAX = ORDER - 1;        

class Node{
public:
    int keys[MAX + 1];           
    Node* child[ORDER + 1];
    int n;                        
    bool leaf;

    Node(bool isLeaf){
        leaf = isLeaf;
        n = 0;
        for(int i = 0; i < ORDER + 1; i++){
            child[i] = nullptr;
        }    
    }
};

class BTree{
    Node* root;

public:
    BTree(){
        root = nullptr;
    }

    void insert(int key);
    void splitChild(Node* parent, int index);
    void insertNonFull(Node* node, int key);
    void display(Node* node, int level);
    void show();
};

void BTree::insert(int key){
    if(root == nullptr){
        root = new Node(true);
        root->keys[0] = key;
        root->n = 1;
        return;
    }

    if(root->n == MAX){
        cout << "\nNo of keys full. Splitting root\n";
        Node* newRoot = new Node(false);
        newRoot->child[0] = root;

        splitChild(newRoot, 0);

        int i = (newRoot->keys[0] < key) ? 1 : 0;
        insertNonFull(newRoot->child[i], key);

        root = newRoot;
    }else{
        insertNonFull(root, key);
    }
}

void BTree::splitChild(Node* parent, int index){
    Node* fullNode = parent->child[index];
    Node* newNode = new Node(fullNode->leaf);

    int mid = MAX / 2; 

    cout << "Split node, Move median up: " << fullNode->keys[mid] << endl;

    newNode->n = MAX - mid - 1;

    for(int i = 0; i < newNode->n; i++){
        newNode->keys[i] = fullNode->keys[i + mid + 1];
    }
    if(!fullNode->leaf){
        for (int i = 0; i <= newNode->n; i++){
            newNode->child[i] = fullNode->child[i + mid + 1];
        }    
    }

    fullNode->n = mid;

    for(int i = parent->n; i >= index + 1; i--){
        parent->child[i + 1] = parent->child[i];
    }
    parent->child[index + 1] = newNode;

    for (int i = parent->n - 1; i >= index; i--){
        parent->keys[i + 1] = parent->keys[i];
    }
    
    parent->keys[index] = fullNode->keys[mid];
    parent->n++;
}

void BTree::insertNonFull(Node* node, int key){
    int i = node->n - 1;

    if(node->leaf){
        while(i >= 0 && node->keys[i] > key){
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->n++;
    }else{
        while(i >= 0 && node->keys[i] > key) i--;

        if(node->child[i + 1]->n == MAX){
            splitChild(node, i + 1);
            if(node->keys[i + 1] < key) i++;
        }
        insertNonFull(node->child[i + 1], key);
    }
}

void BTree::display(Node* node, int level){
    if(node == nullptr) return;

    cout << "Level " << level << " : ";
    for(int i = 0; i < node->n; i++){
        cout << node->keys[i] << " ";
    }    
    cout << endl;

    for(int i = 0; i <= node->n; i++){
        display(node->child[i], level + 1);
    }    
}

void BTree::show(){
    cout << "\nFinal B-Tree Structure:\n";
    display(root, 0);
}

int main(){
    BTree tree;
    int n, key;

    cout << "Enter number of keys: ";
    cin >> n;

    cout << "Enter keys:\n";
    for(int i = 0; i < n; i++){
        cin >> key;
        tree.insert(key);
    }

    tree.show();
    return 0;
}
