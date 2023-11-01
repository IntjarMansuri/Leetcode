// Approach : DFS + Extra Space
// T.C and S.C : O(N)

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n == 0) {
        return NULL;
    }

    int rv;
    cout << "Enter the value of the root node: ";
    cin >> rv;

    TreeNode* root = new TreeNode(rv);
    n--;

    queue<TreeNode*> nq;
    nq.push(root);

    while (n > 0) {
        TreeNode* curr = nq.front();
        nq.pop();

        int leftValue, rightValue;
        cout << "Enter the left child value of node " << curr->val << ": ";
        cin >> leftValue;

        if (leftValue != -1) {
            curr->left = new TreeNode(leftValue);
            nq.push(curr->left);
            n--;
        }

        cout << "Enter the right child value of node " << curr->val << ": ";
        cin >> rightValue;

        if (rightValue != -1) {
            curr->right = new TreeNode(rightValue);
            nq.push(curr->right);
            n--;
        }
    }
    return root;
}

unordered_map<int, int>mp;
void dfs(TreeNode* root) {
    if(!root) {
        return ;
    }

    dfs(root->left);
    mp[root->val]++;
    dfs(root->right);
}

vector<int> findMode(TreeNode* root) {
    dfs(root);

    vector<int>result;
    int maxFreq = 0;

    for(auto x : mp) {
        if(x.second > maxFreq) {
            maxFreq = x.second;
            result = {};
            result.push_back(x.first);
        }
        else if(x.second == maxFreq) {
            result.push_back(x.first);
        }
    }
    return result;
}

int main() {
    TreeNode* root = buildTree();

    vector<int> result = findMode(root);

    for(int val : result) {
        cout << val << " ";
    }

    return 0;

}