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
