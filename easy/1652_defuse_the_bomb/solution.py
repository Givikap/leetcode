from typing import List


class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        code_len = len(code)

        if k == 0:
            return [0] * code_len

        decrypted_code = []

        if k > 0:
            next_k_sum = sum(code[i % code_len] for i in range(1, k + 1))
            i = (k + 1) % code_len

            for _ in range(code_len):
                decrypted_code.append(next_k_sum)
                next_k_sum += code[i % code_len] - code[(i - k) % code_len]
                i = (i + 1) % code_len
        else:
            prev_k_sum = sum(
                code[i % code_len] for i in range(code_len + k, code_len)
            )
            i = 0

            for _ in range(code_len):
                decrypted_code.append(prev_k_sum)
                prev_k_sum += code[i % code_len] - code[(i + k) % code_len]
                i = (i + 1) % code_len

        return decrypted_code
