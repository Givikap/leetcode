from typing import List
from utils.util import Trie

class Solution:
    def longestWord(self, words: List[str]) -> str:
        trie = Trie()

        for word in words:
            trie.insert(word)

        queue = [("", trie.root)]
        longestWord = ""

        while queue:
            word, node = queue.pop(0) 

            if len(word) > len(longestWord) or (len(word) == len(longestWord) and word < longestWord):
                longestWord = word

            for ch in sorted(node.children.keys()):
                child = node.children[ch]

                if child.isWord:
                    queue.append((word + ch, child))

        return longestWord