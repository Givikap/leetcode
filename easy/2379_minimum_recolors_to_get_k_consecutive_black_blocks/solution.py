class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        black_count = 0

        for i in range(k):
            if blocks[i] == "B":
                black_count += 1

        recolors_count = k - black_count

        if len(blocks) == k:
            return recolors_count

        for i in range(k, len(blocks)):
            if blocks[i - k] == "B":
                black_count -= 1

            if blocks[i] == "B":
                black_count += 1

            recolors_count = min(recolors_count, k - black_count)

        return recolors_count
