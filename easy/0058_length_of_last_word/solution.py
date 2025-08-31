class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return len(s.rstrip()) - s.rstrip().rfind(" ") - 1
