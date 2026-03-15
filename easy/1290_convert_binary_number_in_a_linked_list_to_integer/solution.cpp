#include "../../utils/cpp/nodes.hpp"

class Solution {
public:
  int getDecimalValue(utils::ListNode *head) {
    int decimalValue = 0;

    while (head) {
      decimalValue = decimalValue << 1 ^ head->val;
      head = head->next;
    }

    return decimalValue;
  }
};
