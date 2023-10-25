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

vector<int>result;

void DFS(TreeNode* root, int depth) {
    if(!root) return;

    if(depth == result.size()) {
        result.push_back(root->val);
    }
    else {
        result[depth] = max(result[depth], root->val);
    }
    DFS(root->left, depth+1);
    DFS(root->right, depth+1);
}

vector<int> findLargestValues(TreeNode* root) {
    DFS(root, 0);
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