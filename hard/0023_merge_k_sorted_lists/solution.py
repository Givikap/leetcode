import heapq
from typing import List, Optional

from utils.python.nodes import ListNode


class Solution:
    def mergeKLists(
        self, lists: List[Optional[ListNode]]
    ) -> Optional[ListNode]:
        heap = []

        for head in lists:
            if head:
                heapq.heappush(heap, (head.val, head))

        dummy = ListNode(-1)
        curr = dummy

        while heap:
            _, node = heapq.heappop(heap)

            curr.next = node
            curr = curr.next

            if node.next:
                heapq.heappush(heap, (node.next.val, node.next))

        return dummy.next
