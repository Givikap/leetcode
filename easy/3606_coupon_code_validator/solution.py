import re
from typing import List


class Solution:
    def validateCoupons(
        self,
        coupons: List[str],
        business_lines: List[str],
        are_active: List[bool],
    ) -> List[str]:
        valid_business_lines = set(
            ["electronics", "grocery", "pharmacy", "restaurant"]
        )
        business_lines_order = {
            "electronics": 0,
            "grocery": 1,
            "pharmacy": 2,
            "restaurant": 3,
        }

        return [
            coupon
            for _, coupon in sorted(
                [
                    (business_lines_order[business_line], coupon)
                    for coupon, business_line, is_active in zip(
                        coupons, business_lines, are_active
                    )
                    if is_active
                    and business_line in valid_business_lines
                    and re.fullmatch(r"[A-Za-z0-9_]+", coupon)
                ]
            )
        ]
