#Key: BinaryTree
#Algorithm: recursion

#so the ans.append occurs at the end of recursion

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def postorderTraversal(self, root):
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
                check(root.right)
                ans.append(root.val)
        check(root)
        return ans