class Solution:
    def isPathCrossing(self, path: str) -> bool:
        x = y = 0
        visited = set()

        for direction in path:
            visited.add((x, y))

            if direction == "N":
                y += 1
            elif direction == "E":
                x += 1
            elif direction == "S":
                y -= 1
            elif direction == "W":
                x -= 1

            if (x, y) in visited:
                return True

        return False
