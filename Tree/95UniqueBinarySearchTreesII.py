# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n == 0:
            return []
        return self.helper(1, n + 1)
    
    def helper(self, start, end):
        if start == end:
            return None
        res = []
        for i in xrange(start, end):
            for l in self.helper(start, i) or [None]:
                for r in self.helper(i + 1, end) or [None]:
                    node = TreeNode(i)
                    node.left, node.right = l, r
                    res.append(node)
        return res