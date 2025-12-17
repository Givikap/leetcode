from typing import List


class Solution:
    @staticmethod
    def isalnumorunderscore(s: str) -> bool:
        if not s:
            return False

        for c in s:
            if not c.isalnum() and c != "_":
                return False

        return True

    def validateCoupons(
        self,
        coupons: List[str],
        business_lines: List[str],
        are_active: List[bool],
    ) -> List[str]:
        valid_business_lines = set(
            ["electronics", "grocery", "pharmacy", "restaurant"]
        )

        return [
            coupon
            for _, coupon in sorted(
                [
                    (business_line, coupon)
                    for coupon, business_line, is_active in zip(
                        coupons, business_lines, are_active
                    )
                    if is_active
                    and business_line in valid_business_lines
                    and self.isalnumorunderscore(coupon)
                ]
            )
        ]
