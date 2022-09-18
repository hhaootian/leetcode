# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        level = 0
        que = [root]

        while que:
            nxt = []
            vals = []
            for i in range(len(que)):
                node = que[i]
                vals.append(node.val)
                if node.left:
                    nxt.append(node.left)
                    nxt.append(node.right)
            
            
            if level % 2 == 1:
                for i in range(len(que)):
                    que[i].val = vals[len(vals) - 1 - i]
            que = nxt
            level += 1

        return root