#key: BinaryTree
#Algorithm: recursion

#the key of recursion is the two return, one is the end of trip, the other one is
#the end of the recursion. so in this case, when the recursion ends, return the depth+1


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """ 
        if not root:
            return 0
        else:
            left = self.maxDepth(root.left)
            right = self.maxDepth(root.right)
            return max(left+1,right+1)