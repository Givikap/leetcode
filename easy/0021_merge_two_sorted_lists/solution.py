from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1 and not list2:
            return None

        if (list1 and list2 and list1.val <= list2.val) or (list1 and not list2):
            merged_list = list1
            list1 = list1.next
        else:
            merged_list = list2
            list2 = list2.next
            
        curr = merged_list

        while list1 or list2:
            if (list1 and list2 and list1.val <= list2.val) or (list1 and not list2):
                curr.next = list1
                list1 = list1.next
            else:
                curr.next = list2
                list2 = list2.next

            curr = curr.next

        return merged_list
        