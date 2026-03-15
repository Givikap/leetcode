#include "../../utils/cpp/nodes.hpp"

class Solution {
public:
  utils::ListNode *swapPairs(utils::ListNode *head) {
    if (!head)
      return nullptr;

    utils::ListNode *dummy = new utils::ListNode(-1, head);

    utils::ListNode *prev = dummy;
    utils::ListNode *curr = head;
    utils::ListNode *temp;

    while (curr) {
      if (curr->next) {
        temp = curr->next;
        prev->next = temp;
        curr->next = temp->next;
        temp->next = curr;
      }

      prev = curr;
      curr = curr->next;
    }

    return dummy->next;
  }
};
