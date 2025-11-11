from collections import defaultdict


class Solution:
    def countLargestGroup(self, n: int) -> int:
        groups_counter = defaultdict(int)

        for i in range(1, n + 1):
            if i < 10:
                group = i
            else:
                group = 0

                while i:
                    group += i % 10
                    i //= 10

            groups_counter[group] += 1

        return sum(
            1
            for val in groups_counter.values()
            if val == max(groups_counter.values())
        )
