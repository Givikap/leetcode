#include <unordered_map>

struct LRUNode {
  int key;
  int val;
  LRUNode *prev;
  LRUNode *next;
  LRUNode(int key, int val)
      : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
  int capacity;
  LRUNode *head;
  LRUNode *tail;
  std::unordered_map<int, LRUNode *> cacheMap;

  void update(LRUNode *node) {
    if (node == head)
      return;

    if (node->prev)
      node->prev->next = node->next;
    if (node->next)
      node->next->prev = node->prev;

    if (node == tail)
      tail = node->prev;

    node->prev = nullptr;
    node->next = head;

    if (head)
      head->prev = node;
    head = node;
  }

public:
  LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {}

  int get(int key) {
    if (cacheMap.find(key) != cacheMap.end()) {
      LRUNode *node = cacheMap[key];
      update(node);
      return node->val;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    if (cacheMap.find(key) != cacheMap.end()) {
      LRUNode *node = cacheMap[key];
      node->val = value;
      update(node);
    } else {
      LRUNode *node = new LRUNode(key, value);
      cacheMap[key] = node;

      if (head) {
        head->prev = node;
        node->next = head;
      } else {
        tail = node;
      }

      head = node;
    }

    if (cacheMap.size() > capacity) {
      cacheMap.erase(tail->key);

      tail = tail->prev;
      if (tail)
        tail->next = nullptr;
    }
  }
};
