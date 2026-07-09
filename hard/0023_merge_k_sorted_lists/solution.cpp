#include "../../utils/cpp/nodes.hpp"
#include <vector>

class Solution {
public:
  utils::ListNode *mergeKLists(std::vector<utils::ListNode *> &lists) {
    std::vector<utils::ListNode *> heap;
    auto cmp = [](utils::ListNode *a, utils::ListNode *b) {
      return a->val > b->val;
    };

    for (utils::ListNode *list : lists) {
      if (list) {
        heap.push_back(list);
        push_heap(heap.begin(), heap.end(), cmp);
      }
    }

    utils::ListNode *dummy = new utils::ListNode(-10001);
    utils::ListNode *curr = dummy;

    while (!heap.empty()) {
      curr->next = heap.front();

      pop_heap(heap.begin(), heap.end(), cmp);
      heap.pop_back();

      curr = curr->next;
      if (curr->next) {
        heap.push_back(curr->next);
        push_heap(heap.begin(), heap.end(), cmp);
      }
    }
    curr->next = nullptr;

    return dummy->next;
  }
};
