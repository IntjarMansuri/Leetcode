#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to convert a vector of integer to a binary tree
TreeNode* vectorToTree(vector<int>& nodes) {
    if(nodes.empty()) return NULL;

    queue<TreeNode*>nodeQueue;
    TreeNode* root = new TreeNode(nodes[0]);
    nodeQueue.push(root);

    int i = 1;
    while(!nodeQueue.empty() && i < nodes.size()) {
        TreeNode* currNode = nodeQueue.front();
        nodeQueue.pop();

        if(nodes[i] != -1) {
            currNode->left = new TreeNode(nodes[i]);
            nodeQueue.push(currNode->left);
        }
        i++;

        if(i < nodes.size() && nodes[i] != -1) {
            currNode->right = new TreeNode(nodes[i]);
            nodeQueue.push(currNode->right);
        }
        i++;
    }
    return root;
}

// Function to perform level-order traversal and print the binary tree
void levelOrderTraversal(TreeNode* root) {
    if(!root)
        return;

    queue<TreeNode*>nodeQueue;
    nodeQueue.push(root);

    while(!nodeQueue.empty()) {
        TreeNode* currNode = nodeQueue.front();
        nodeQueue.pop();

        cout << currNode->val << " ";
        if(currNode->left != NULL) {
            nodeQueue.push(currNode->left);
        }

        if(currNode->right != NULL) {
            nodeQueue.push(currNode->right);
        }
    }
}


int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<int> nodes(n);
    cout << "Enter node values (use -1 for NULL): ";
    for(int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    TreeNode* root = vectorToTree(nodes);

    cout << "Level Order Traversal of the Binary Tree: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}