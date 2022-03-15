/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        vector<int> left = inorderTraversal(root->left);
        vector<int> ans = {root->val};
        vector<int> right = inorderTraversal(root->right);
        left.insert(left.end(), ans.begin(), ans.end());
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};