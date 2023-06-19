# Definition for singly-linked list.
from copy import deepcopy
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        s1 = ""
        s2 = ""
        while(l1 != None):
            s1 = s1 + str(l1.val)
            l1 = l1.next
        while(l2 != None):
            s2 = s2 + l2.val
            l2 = l2.next
        sum = int(s1[::-1]) + int(s2[::-1])
        ans = ListNode(sum%10)
        prev = ans
        sum /= 10
        while(sum > 0):
            newNode = ListNode(sum%10)
            prev.next = newNode
            prev = newNode
            sum /= 10
        return ans

