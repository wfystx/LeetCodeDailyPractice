#Key: binaryTree
#algorithm: Recursion

#The node must remember where it just arrive. so ans.append first, and then go to its left and right
#The recursion must have a base case, which is when it meet an end node, that's the reason if and else 

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans = []
        def check(root):
            if not root:
                return
            else:
                ans.append(root.val)
                check(root.left)
                check(root.right)
        check(root)
        return ans