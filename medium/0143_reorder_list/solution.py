from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        in_order = slow = fast = head
        prev_slow = None
        
        while fast:
            prev_slow = slow
            slow = slow.next
            fast = fast.next

            if fast:
                fast = fast.next

        prev_slow.next = None

        curr = slow
        prev = None

        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp

        reverse = prev

        reordered = in_order
        in_order = in_order.next

        curr = reordered

        while reverse:
            curr.next = reverse
            curr = curr.next
            reverse = reverse.next

            if in_order:
                curr.next = in_order
                curr = curr.next
                in_order = in_order.next