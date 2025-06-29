import heapq
from typing import List, Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __lt__(self, other):
        return self.val < other.val

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        lists = [l for l in lists if l]

        if not lists:
            return None

        dummy = ListNode(-1)
        curr = dummy

        while lists:
            heapq.heapify(lists)

            curr.next = lists[0]
            curr = curr.next

            if lists[0].next:
                lists[0] = lists[0].next
            else: 
                lists = lists[1:]
