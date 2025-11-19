from typing import Optional

from utils.python.nodes import ListNode


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head

        if fast:
            fast = fast.next

        while fast:
            if slow and fast and slow == fast:
                return True

            slow = slow.next
            fast = fast.next

            if fast:
                fast = fast.next

        return False
