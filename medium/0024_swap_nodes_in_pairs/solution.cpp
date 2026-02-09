using namespace std;

#include "../../utils/cpp/nodes.hpp"

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (!head)
      return nullptr;

    ListNode *dummy = new ListNode(-1, head);

    ListNode *prev = dummy;
    ListNode *curr = head;
    ListNode *temp;

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
