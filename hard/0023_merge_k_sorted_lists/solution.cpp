#include "../../utils/cpp/nodes.hpp"
#include <vector>

class Solution {
public:
  utils::ListNode *mergeKLists(std::vector<utils::ListNode *> &lists) {
    std::vector<utils::ListNode *> heap;
    auto cmp = [](utils::ListNode *a, utils::ListNode *b) {
      return a->val > b->val;
    };

    for (size_t i = 0; i < lists.size(); ++i) {
      while (lists[i]) {
        heap.push_back(lists[i]);
        push_heap(heap.begin(), heap.end(), cmp);
        lists[i] = lists[i]->next;
      }
    }

    utils::ListNode *dummy = new utils::ListNode(-10001);
    utils::ListNode *curr = dummy;

    while (!heap.empty()) {
      curr->next = heap.front();
      pop_heap(heap.begin(), heap.end(), cmp);
      heap.pop_back();
      curr = curr->next;
    }
    curr->next = nullptr;

    return dummy->next;
  }
};
