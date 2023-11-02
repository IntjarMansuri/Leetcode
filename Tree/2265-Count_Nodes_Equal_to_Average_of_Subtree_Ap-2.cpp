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

pair<int, int> solve(TreeNode* root) {
    if(!root) {
        return {0, 0};
    }

    auto p1 = solve(root->left);
    auto p2 = solve(root->right);

    int totalSum = p1.first + p2.first + root->val;
    int totalCount = p1.second + p2.second + 1;

    int avg = totalSum/totalCount;

    if(avg == root->val) {
        result += 1;
    }

    return { totalSum, totalCount };
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

// Approach : Doint PostOrder Traversal
// Time : O(N), Space : O(1)