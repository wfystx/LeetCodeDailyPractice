#Merge sort example

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        
        def merge(a,b):
            dummy = ListNode(0)
            p = dummy
            while a or b:
                if not a:
                    p.next, b = b, b.next
                elif not b:
                    p.next, a = a, a.next
                elif a.val < b.val:
                    p.next, a = a, a.next
                else:
                    p.next, b = b, b.next
                p = p.next
            return dummy.next
        
        s, f, pre = head,head,None
        while f and f.next:
            s, f, pre = s.next, f.next.next, s
        pre.next = None
        
        return merge(self.sortList(head),self.sortList(s))