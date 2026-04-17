class Solution:
    def defangIPaddr(self, address: str) -> str:
        defanged_address = []

        for c in address:
            if c == ".":
                defanged_address.append("[.]")
            else:
                defanged_address.append(c)

        return "".join(defanged_address)
