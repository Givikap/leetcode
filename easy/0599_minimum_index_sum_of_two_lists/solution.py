from typing import List


class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        list1Map = {restaurant: i for i, restaurant in enumerate(list1)}

        minIndex = float("inf")
        commonRestaurants = []

        for i, restaurant in enumerate(list2):
            if restaurant in list1Map:
                currIndex = i + list1Map[restaurant]

                if currIndex == minIndex:
                    commonRestaurants.append(restaurant)
                elif currIndex < minIndex:
                    minIndex = currIndex
                    commonRestaurants = [restaurant]

        return commonRestaurants
