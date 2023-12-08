#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Build Binary Tree
TreeNode* vectorToTree(vector<int>& nodes) {
    if(nodes.empty()) return NULL;

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(nodes[0]);
    q.push(root);

    int i = 1;
    while(!q.empty() && i < nodes.size()) {
        TreeNode* currNode = q.front();
        q.pop();

        if(nodes[i] != -1) {
            currNode->left = new TreeNode(nodes[i]);
            q.push(currNode->left);
        }
        i++;

        if(i < nodes.size() && nodes[i] != -1) {
            currNode->right = new TreeNode(nodes[i]);
            q.push(currNode->right);
        }
        i++;
    }
    return root;
}

string tree2str(TreeNode* root) {
    if(root == NULL) {
        return "";
    }

    string result = to_string(root->val);

    string LEFT = tree2str(root->left);
    string RIGHT = tree2str(root->right);

    if(root->left == NULL && root->right == NULL) {
        return result;
    }

    if(root->left == NULL) {
        return result + "()" + "(" + RIGHT + ")";
    }

    if(root->right == NULL) {
        return result + "(" + LEFT + ")";
    }

    return result + "(" + LEFT + ")" + "(" + RIGHT + ")";
}

int main() {
    int n;
    cin >> n;

    vector<int> nodes(n);
    for(int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    TreeNode* root = vectorToTree(nodes);
    string result = tree2str(root);
    cout << result << endl;

    return 0;
}