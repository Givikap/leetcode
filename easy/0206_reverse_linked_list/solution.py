from typing import Optional
from utils.util import ListNode

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None

        while head:
            head.next, prev, head = prev, head, head.next

        return prev