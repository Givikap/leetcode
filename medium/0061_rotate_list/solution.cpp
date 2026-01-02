using namespace std;

#include "../../utils/cpp/nodes.hpp"

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next || k == 0)
      return head;

    ListNode *curr, *back;

    int listLen = 0;

    curr = head;
    while (curr) {
      back = curr;
      curr = curr->next;
      ++listLen;
    }

    k = listLen - k % listLen - 1;

    curr = head;
    for (int _ = 0; _ < k; ++_)
      curr = curr->next;

    back->next = head;
    head = curr->next;
    curr->next = nullptr;

    return head;
  }
};
