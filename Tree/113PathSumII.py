# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        res = []
        self.dfs(res, [], root, sum)
        return res
    
    def dfs(self, res, tmp, root, sum):
        if not root:
            return
        if not root.left and not root.right and root.val == sum:
            tmp.append(root.val)
            res.append(tmp)
            return
        
        self.dfs(res, tmp + [root.val], root.left, sum - root.val)
        self.dfs(res, tmp + [root.val], root.right, sum - root.val)