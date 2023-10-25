#include<bits/stdc++.h>
using namespace std;

struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

TreeNode* createTree() {
    int val;
    cin >> val;

    if(val == -1) {
        return NULL;
    }

    TreeNode* root = new TreeNode(val);
    root->left = createTree();
    root->right = createTree();

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
    TreeNode* root = createTree();

    vector<int> result = findLargestValues(root);

    cout << "Largest values in each level: ";
    for(int val : result) {
        cout << val << " ";
    }

    return 0;
}

// Approach 1 : BFS (Bredth First Search)
// T.C = O(n)
// S.C = O(n)