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
    bool hasPathSum(TreeNode* root, int targetSum, int pre=0) {
        if (!root)
            return false;
        
        pre += root->val;

        if (!root->left && !root->right) {
            if (pre == targetSum)
                return true;
            return false;
        }

        bool left = hasPathSum(root->left, targetSum, pre);
        bool right = hasPathSum(root->right, targetSum, pre);
        return left || right;
    }
};