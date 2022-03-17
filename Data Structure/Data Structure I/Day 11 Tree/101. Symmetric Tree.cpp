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
    bool helper(TreeNode* ptr1, TreeNode* ptr2) {
        if (!ptr1 && !ptr2)
            return true;
        if (!ptr1 || !ptr2)
            return false;
        return (ptr1->val == ptr2->val) && helper(ptr1->left, ptr2->right) && helper(ptr1->right, ptr2->left);
    }

    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
};