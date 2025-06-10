from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head.next:
            return None

        if not head.next.next:
            if n == 2:
                head = head.next
            else:
                head.next = None

            return head

        fast, slow = head, head
        length = 0

        for i in range(n):
            fast = fast.next

        if not fast:
            return head.next

        while fast:
            fast = fast.next

            if fast:
                slow = slow.next

        slow.next = slow.next.next
        
        return head