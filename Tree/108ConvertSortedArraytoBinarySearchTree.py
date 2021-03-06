# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if not nums:
            return None
        m = len(nums) / 2
        root = TreeNode(nums[m])
        l = nums[:m]
        r = nums[m + 1:]
        root.left = self.sortedArrayToBST(l)
        root.right = self.sortedArrayToBST(r)
        return root