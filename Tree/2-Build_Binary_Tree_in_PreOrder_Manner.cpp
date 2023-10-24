#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int  val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree() {
    int val;
    cin >> val;
    if (val == -1) {
        return nullptr;
    }

    TreeNode* node = new TreeNode(val);
    cout << "Enter left child of " << val << ": ";
    node->left = buildTree();
    cout << "Enter right child of " << val << ": ";
    node->right = buildTree();

    return node;
}

void preorderTraversal(TreeNode* root) {
    if (root) {
        cout << root->val << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->val << " ";
    }
}

int main() {
    cout << "Enter the root value (or -1 to indicate a null node): ";
    TreeNode* root = buildTree();

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}