class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end

class ListNode:
    def __init__(self, val: int = 0, next: "ListNode" = None):
        self.val = val
        self.next = next

    def __lt__(self, other: "ListNode"):
        return self.val < other.val
    
class TreeNode:
    def __init__(self, val: int = 0, left: "TreeNode" = None, right: "TreeNode" = None):
        self.val = val
        self.left = left
        self.right = right

class TrieNode:
    def __init__(self):
        self.children: dict[str, "TrieNode"] = {}
        self.isWord = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        curr = self.root

        for ch in word:
            if ch not in curr.children:
                curr.children[ch] = TrieNode()
            
            curr = curr.children[ch]

        curr.isWord = True
