from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head.next:
            return None

        fast = head
        
        for i in range(n):
            fast = fast.next

        if not fast:
            return head.next

        fast = fast.next
        slow = head

        while fast:
            fast = fast.next
            slow = slow.next

        slow.next = slow.next.next
    
        return head