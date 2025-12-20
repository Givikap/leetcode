from typing import Optional

from utils.python.nodes import ListNode


class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = ListNode(-1)
        curr = dummy

        carry = 0

        while l1 or l2 or carry:
            if l1 and l2:
                new_val = l1.val + l2.val
                l1 = l1.next
                l2 = l2.next
            elif l1:
                new_val = l1.val
                l1 = l1.next
            elif l2:
                new_val = l2.val
                l2 = l2.next
            else:
                new_val = 0

            new_val += carry
            carry = new_val > 9

            curr.next = ListNode(new_val % 10)
            curr = curr.next

        return dummy.next
