class LRUNode:
    def __init__(self, key: int, val: int):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None


class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.head = None
        self.tail = None
        self.cacheMap = {}

    def __update(self, node: LRUNode):
        if node == self.head:
            return

        if node.prev:
            node.prev.next = node.next
        if node.next:
            node.next.prev = node.prev

        if node == self.tail:
            self.tail = node.prev

        node.prev = None
        node.next = self.head

        if self.head:
            self.head.prev = node
        self.head = node

    def get(self, key: int) -> int:
        if key in self.cacheMap:
            node = self.cacheMap[key]
            self.__update(node)
            return node.val
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cacheMap:
            node = self.cacheMap[key]
            node.val = value
            self.__update(node)
        else:
            node = LRUNode(key, value)
            self.cacheMap[key] = node

            if self.head:
                node.next = self.head
                self.head.prev = node
            else:
                self.tail = node

            self.head = node

        if len(self.cacheMap) > self.capacity:
            self.cacheMap.pop(self.tail.key)

            self.tail = self.tail.prev
            if self.tail:
                self.tail.next = None
