class Solution:
    def isHappy(self, n: int) -> bool:
        visited = set()

        while n != 1:
            n = sum([int(digit) ** 2 for digit in str(n)])

            if n in visited:
                return False

            visited.add(n)
        
        return True