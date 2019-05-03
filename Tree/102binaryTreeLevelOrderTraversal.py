#key: binaryTree
#Algorithm: queue

#the key is to traval all the node by level, after travaling all node at the same level,
#saving them to the ans, and then go to the next level.

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ans = []
        level = [root]
        if not root:
            return []
            
        while level:
            temp = []
            ans.append([node.val for node in level])
            for node in level:
                temp.extend([node.left,node.right])
            level = [leaf for leaf in temp if leaf]
        return ans