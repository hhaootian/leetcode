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
    int sumOfLeftLeaves(TreeNode* root, bool isLeft=false) {
        if (!root)
            return 0;
        if (!root->left && !root->right && isLeft)
            return root->val;
        int left = sumOfLeftLeaves(root->left, true);
        int right = sumOfLeftLeaves(root->right, false);
        return left + right;
    }
};