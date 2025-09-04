from typing import Optional

from utils.nodes import ListNode


class Solution:
    def getIntersectionNode(
        self, head_a: ListNode, head_b: ListNode
    ) -> Optional[ListNode]:
        if not head_a or not head_b:
            return None

        p_a, p_b = head_a, head_b

        while p_a is not p_b:
            p_a = p_a.next if p_a else head_b
            p_b = p_b.next if p_b else head_a

        return p_a
