#include<bits/stdc++.h>
using namespace std;

struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

// Function to create a binary tree in preorder manner
TreeNode* createTree(vector<int>& preorder, int& index) {
    if (index >= preorder.size() || preorder[index] == -1) {
        index++;
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[index]);
    index++;
    root->left = createTree(preorder, index);
    root->right = createTree(preorder, index);

    return root;
}

vector<int> findLargestValues(TreeNode* root) {
    if(!root) return {};

    queue<TreeNode*>q;
    q.push(root);

    vector<int>result;
    while(!q.empty()) {
        int levelSize = q.size();
        int currentMax = INT_MIN;

        for(int i = 0; i < levelSize; i++) {

            TreeNode* node = q.front();
            q.pop();
            currentMax = max(currentMax, node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        result.push_back(currentMax);
    }
    return result;
}


int main() {
    vector<int> preorder;

    int val;
    while (cin >> val) {
        preorder.push_back(val);
    }

    int index = 0;

    TreeNode* root = createTree(preorder, index);

    vector<int> result = findLargestValues(root);

    cout << "Largest values in each level: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}

// Approach 1 : BFS
// T.C = O(n)
// S.C = O(n)