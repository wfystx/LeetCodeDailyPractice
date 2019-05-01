#ListNode

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l3 = temp = ListNode(0)
        carry = 0
        
        while l1 or l2 or carry:
            n1, n2 = 0, 0
            if l1:
                n1 = l1.val
                l1 = l1.next
            if l2:
                n2 = l2.val
                l2 = l2.next
            s = n1 + n2 + carry
            carry = s/10
            remainder = s%10
            temp.next = ListNode(remainder)
            temp = temp.next
        return l3.next