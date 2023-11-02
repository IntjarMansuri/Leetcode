#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& nodes) {
    if(nodes.empty()) return NULL;

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(nodes[0]);
    q.push(root);

    int i = 1;
    while(!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if(nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if(i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int result;

int sum(TreeNode* root, int &count) {
    if(!root) {
        return 0;
    }
    count++;

    int l = sum(root->left, count);
    int r = sum(root->right, count);

    return l + r + root->val;
}

void solve(TreeNode* root) {
    if(!root)
        return;

    int count = 0;
    int totalSum = sum(root, count);
    
    if((totalSum)/count == root->val) {
        result++;
    }

    solve(root->left);
    solve(root->right);
}

int averageOfSubstree(TreeNode* root) {
    result = 0;

    solve(root);

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> nodes(n);
    for(int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    TreeNode* root = buildTree(nodes);
    
    int ans = averageOfSubstree(root);

    cout << ans << endl;

    return 0;
}

// Approach : Burtforce
// Time : O(n^2), Space : O(1)