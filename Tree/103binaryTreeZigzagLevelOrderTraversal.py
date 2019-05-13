# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        q = collections.deque([root])
        res = []
        
        while q:
            temp = []
            for _ in range(len(q)):
                p = q.popleft()
                if p:
                    temp.append(p.val)
                    q.append(p.left)
                    q.append(p.right)
            if len(res) % 2:
                temp = temp[::-1]
            if temp:
                res.append(temp)
        return res 
    
    
    