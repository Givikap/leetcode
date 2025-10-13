from typing import List


class Solution:
    def countSeniors(self, details: List[str]) -> int:
        return len([0 for detail in details if int(detail[11:13]) > 60])
