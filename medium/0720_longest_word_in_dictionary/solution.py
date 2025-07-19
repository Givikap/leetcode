from collections import deque
from typing import List
from utils.util import Trie

class Solution:
    def longestWord(self, words: List[str]) -> str:
        trie = Trie()

        for word in words:
            trie.insert(word)

        nodesDeque = deque([("", trie.root)])
        longestWord = ""

        while nodesDeque:
            word, node = nodesDeque.popleft() 

            if (len(word) > len(longestWord) 
                    or (len(word) == len(longestWord) and word < longestWord)):
                longestWord = word

            for ch in node.children.keys():
                child = node.children[ch]

                if child.isWord:
                    nodesDeque.append((word + ch, child))

        return longestWord