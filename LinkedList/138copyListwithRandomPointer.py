# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        queue = []
        copy = {}
        if not head:
            return
        queue.append(head)
        copy[head] = Node(head.val,None,None)
        while queue:
            cur = queue.pop(0)
            n,r = cur.next,cur.random
            if n:
                if n not in copy:
                    copy[n] = Node(n.val,None,None)
                queue.append(n)
                copy[cur].next = copy[n]
            if r:
                if r not in copy:
                    copy[r] = Node(r.val,None,None)
                copy[cur].random = copy[r]
        return copy[head]