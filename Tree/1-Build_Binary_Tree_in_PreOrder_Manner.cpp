#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int data) {
        this->data = data;
        Node* left = NULL;
        Node* right = NULL;
    }
};

Node* buildBinaryTreePreOrder() {
    int d;
    cin >> d;

    if(d == -1) {
        return NULL;
    }

    // Node Exist
    Node* root = new Node(d);
    root->left = buildBinaryTreePreOrder();
    root->right = buildBinaryTreePreOrder();

    return root;
}

void printPreOrder(Node* root) {
    
    // Base Case
    if(!root) return;

    // Recursion Case
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(Node* root) {
    
    // Base Case
    if(!root) return;

    // Recursion Case
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void printPostOrder(Node* root) {

    // Base Case
    if(!root) return;

    // Recursion Case
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int main() {

    Node* root = buildBinaryTreePreOrder();

    printPreOrder(root);
    cout << endl;
    printInOrder(root);
    cout << endl;
    printPostOrder(root);
}