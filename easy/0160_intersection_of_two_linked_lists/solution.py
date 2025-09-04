from typing import Optional

from utils.nodes import ListNode


class Solution:
    def getIntersectionNode(
        self, head_a: ListNode, head_b: ListNode
    ) -> Optional[ListNode]:
        visited = set()

        while head_a or head_b:
            if head_a == head_b:
                return head_a

            if head_a:
                visited.add(head_a)
                head_a = head_a.next
            if head_b:
                visited.add(head_b)
                head_b = head_b.next

            if head_a in visited:
                return head_a
            if head_b in visited:
                return head_b

        return None
