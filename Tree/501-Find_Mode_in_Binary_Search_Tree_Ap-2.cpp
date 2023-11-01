// Approach : DFS
// T.C and S.C : O(n), O(1)

#include <bits/stdc++.h>
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

int currNum = 0;
int currFreq = 0;
int maxFreq = 0;
vector<int> ans;

void dfs(TreeNode* root) {
    if (!root)
        return;

    dfs(root->left);
    if (root->val == currNum) {
        currFreq++;
    }
    else {
        currNum = root->val;
        currFreq = 1;
    }

    if (currFreq > maxFreq) {
        ans = {};
        maxFreq = currFreq;
    }

    if (currFreq == maxFreq) {
        ans.push_back(root->val);
    }

    dfs(root->right);
}

vector<int> findMode(TreeNode* root) {
    dfs(root);

    return ans;
}

int main() {
    TreeNode* root = buildTree();

    vector<int> result = findMode(root);
    cout << "Modes: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
