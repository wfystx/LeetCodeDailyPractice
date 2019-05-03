#key: BinaryTree
#Algorithm: recursion

#like the problem 144, the ans.append should occur behind the root.left
#

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans = []
        
        def check(root):
            if not root:
                return
            else:
                check(root.left)
                ans.append(root.val)
                check(root.right)
        
        check(root)
        return ans