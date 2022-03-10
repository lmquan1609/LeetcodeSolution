# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        def getLength(node):
            length = 0
            while node:
                length += 1
                node = node.next
            return length
        
        lenA, lenB = map(getLength, (headA, headB))
        if lenA > lenB:
            headA, headB = headB, headA
            lenA, lenB = lenB, lenA
        
        diff = lenB - lenA
        nodeA, nodeB = headA, headB
        
        while diff:
            diff -= 1
            nodeB = nodeB.next
        
        while nodeA != nodeB:
            nodeA = nodeA.next
            nodeB = nodeB.next
        return nodeA
