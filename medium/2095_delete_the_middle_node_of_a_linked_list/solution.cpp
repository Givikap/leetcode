#include "../../utils/cpp/nodes.hpp"

class Solution {
public:
  utils::ListNode *deleteMiddle(utils::ListNode *head) {
    if (!head || !head->next)
      return nullptr;

    utils::ListNode *slow = head;
    utils::ListNode *fast = head->next->next;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    slow->next = slow->next->next;

    return head;
  }
};
