def isBadVersion(version: int) -> bool:
    pass


class Solution:
    def firstBadVersion(self, n: int) -> int:
        left = 1
        right = n

        while left <= right:
            mid = (left + right) // 2

            is_bad_version = isBadVersion(mid)

            if is_bad_version and not isBadVersion(mid - 1):
                return mid

            if not is_bad_version:
                left = mid + 1
            else:
                right = mid - 1
