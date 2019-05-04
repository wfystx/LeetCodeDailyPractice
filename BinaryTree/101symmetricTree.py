#BinaryTree
#Recursion

#To comparing, get the matching position, if right then move on or return False
#start considering from the very begining

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def check(left,right):
            if not left and not right:
                return True
            elif not left or not right:
                return False
            elif left.val == right.val:
                leftnext = check(left.left,right.right)
                rightnext = check(left.right,right.left)
                return leftnext and rightnext
            else:
                return False
        
        if not root:
            return True
        else:
            return check(root,root)