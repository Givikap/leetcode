using namespace std;

#include "../../utils/cpp/nodes.hpp"

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy(-1);
    ListNode *curr = &dummy;

    int carry = 0;
    int val1 = 0, val2 = 0, newVal;

    while (l1 != nullptr || l2 != nullptr || carry) {
      val1 = l1 != nullptr ? l1->val : 0;
      val2 = l2 != nullptr ? l2->val : 0;

      l1 = l1 != nullptr ? l1->next : nullptr;
      l2 = l2 != nullptr ? l2->next : nullptr;

      newVal = val1 + val2 + carry;
      carry = newVal / 10;

      curr->next = new ListNode(newVal % 10);
      curr = curr->next;
    }

    return dummy.next;
  }
};
