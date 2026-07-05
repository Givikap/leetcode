from typing import Optional

from utils.python.nodes import ListNode


class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        slow = head
        fast = head

        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next
            if fast:
                fast = fast.next

        if prev:
            prev.next = slow.next
            del slow
        else:
            head = None

        return head
