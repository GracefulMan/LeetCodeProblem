# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        r = 0
        res = ListNode(0)
        p = res
        while l1 and l2:
            tmp = ListNode((l1.val + l2.val + r) % 10)
            p.next = tmp
            p = tmp
            r = (l1.val + l2.val + r) // 10
            l1 = l1.next
            l2 = l2.next
        while l1:
            tmp = ListNode((l1.val + r) % 10)
            r = (l1.val + r) // 10
            p.next = tmp
            p = tmp
            l1 = l1.next
        while l2:
            tmp = ListNode((l2.val + r) % 10)
            r = (l2.val + r) // 10
            p.next = tmp
            p = tmp
            l2 = l2.next
        if r != 0:
            tmp = ListNode(r)
            p.next = tmp
        return res.next