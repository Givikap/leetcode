class Solution:
    def toLowerCase(self, s: str) -> str:
        return "".join(
            [chr(ord(c) + 32) if 64 < ord(c) < 91 else c for c in s]
        )
