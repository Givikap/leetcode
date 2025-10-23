from typing import Optional

from utils.nodes import ListNode


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        nodes = set()

        while head is not None:
            if head in nodes:
                return True

            nodes.add(head)
            head = head.next

        return False
