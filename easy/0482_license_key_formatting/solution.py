class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        s = list(s)

        license_key = []
        l = 0

        while s:
            c = s.pop()

            if c == "-":
                continue

            if l == k:
                license_key.append("-")
                l = 0

            license_key.append(c)
            l += 1

        return "".join(reversed(license_key)).upper()
