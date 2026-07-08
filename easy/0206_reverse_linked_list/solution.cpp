#include "../../utils/cpp/nodes.hpp"

class Solution {
public:
  utils::ListNode *reverseList(utils::ListNode *head) {
    if (!head || !head->next)
      return head;

    utils::ListNode *prev = nullptr;
    utils::ListNode *curr = head;
    utils::ListNode *next = nullptr;

    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
  }
};
