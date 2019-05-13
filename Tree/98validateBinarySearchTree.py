# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def dfs(root, less, top):
            if not root:
                return True
            if root.val >= less or root.val <= top:
                return False
            return dfs(root.left, min(root.val,less), top) and dfs(root.right, less, max(root.val,top))
        
        return dfs(root,float('inf'),float('-inf'))
            