# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        prev = None
        self.helper(root, prev)
        
    def helper(self, root, prev):
        if not root:
            return prev
        prev = self.helper(root.right, prev)
        prev = self.helper(root.left, prev)
        
        root.right = prev
        root.left = None
        prev = root
        return prev