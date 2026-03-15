#include "../../utils/cpp/nodes.hpp"

class Solution {
public:
  utils::ListNode *addTwoNumbers(utils::ListNode *l1, utils::ListNode *l2) {
    utils::ListNode dummy(-1);
    utils::ListNode *curr = &dummy;

    int carry = 0;
    int val1 = 0, val2 = 0, newVal;

    while (l1 != nullptr || l2 != nullptr || carry) {
      val1 = l1 != nullptr ? l1->val : 0;
      val2 = l2 != nullptr ? l2->val : 0;

      l1 = l1 != nullptr ? l1->next : nullptr;
      l2 = l2 != nullptr ? l2->next : nullptr;

      newVal = val1 + val2 + carry;
      carry = newVal / 10;

      curr->next = new utils::ListNode(newVal % 10);
      curr = curr->next;
    }

    return dummy.next;
  }
};
