class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        white_count = 0
        black_count = 0

        for i in range(k):
            if blocks[i] == "W":
                white_count += 1
            else:
                black_count += 1

        recolors_count = k - black_count

        if len(blocks) == k:
            return recolors_count

        for i in range(k, len(blocks)):
            if blocks[i - k] == "W":
                white_count -= 1
            else:
                black_count -= 1

            if blocks[i] == "W":
                white_count += 1
            else:
                black_count += 1

            recolors_count = min(recolors_count, k - black_count)

        return recolors_count
