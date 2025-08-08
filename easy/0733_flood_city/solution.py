from typing import List

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        stack = [(sr, sc)]

        while stack:
            row, col = stack.pop()

            if image[row][col] == color:
                continue

            if row - 1 >= 0 and image[row-1][col] == image[row][col]:
                stack.append((row-1, col))
            if col + 1 < len(image[0]) and image[row][col+1] == image[row][col]:
                stack.append((row, col+1))
            if row + 1 < len(image) and image[row+1][col] == image[row][col]:
                stack.append((row+1, col))
            if col - 1 >= 0 and image[row][col-1] == image[row][col]:
                stack.append((row, col-1))

            image[row][col] = color
            
        return image