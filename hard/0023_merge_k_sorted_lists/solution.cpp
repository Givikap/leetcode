#include "../../utils/cpp/nodes.hpp"
#include <queue>
#include <vector>

class Solution {
public:
  utils::ListNode *mergeKLists(std::vector<utils::ListNode *> &lists) {
    auto cmp = [](utils::ListNode *a, utils::ListNode *b) {
      return a->val > b->val;
    };
    std::priority_queue<utils::ListNode *, std::vector<utils::ListNode *>,
                        decltype(cmp)>
        pq(cmp);

    for (utils::ListNode *list : lists) {
      if (list)
        pq.push(list);
    }

    utils::ListNode *dummy = new utils::ListNode(-10001);
    utils::ListNode *curr = dummy;

    while (!pq.empty()) {
      curr->next = pq.top();
      pq.pop();

      curr = curr->next;
      if (curr->next)
        pq.push(curr->next);
    }
    curr->next = nullptr;

    return dummy->next;
  }
};
