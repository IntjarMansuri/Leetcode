class Solution {
public:
    void inorderTraversal(TreeNode* root, vector<int>& result) {
        if (root != NULL) {
            inorderTraversal(root->left, result);
            result.push_back(root->val);
            inorderTraversal(root->right, result);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }
};