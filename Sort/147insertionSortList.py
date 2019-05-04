#sort & ListNode

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = res = ListNode(None)
        cur = pre.next = head
        
        while cur and cur.next:
            val = cur.next.val
            if cur.val < val:
                cur = cur.next
                continue
            if pre.next > val:
                pre = res
            while pre.next.val < val:
                pre = pre.next
            new = cur.next
            cur.next = new.next
            new.next = pre.next
            pre.next = new
        return res.next