from typing import List


class Robot:
    directions = {0: "North", 90: "East", 180: "South", 270: "West"}
    deltas = {
        0: (0, 1),
        90: (1, 0),
        180: (0, -1),
        270: (-1, 0),
    }

    def __init__(self, width: int, height: int):
        self.width = width
        self.height = height

        self.x = 0
        self.y = 0
        self.direction = 90

    def step(self, num: int) -> None:
        while True:
            dx, dy = self.deltas[self.direction]
            self.x += dx * num
            self.y += dy * num

            num = 0

            if self.x < 0:
                num = -self.x
                self.x = 0
            elif self.x >= self.width:
                num = self.x - (self.width - 1)
                self.x = self.width - 1
            elif self.y < 0:
                num = -self.y
                self.y = 0
            elif self.y >= self.height:
                num = self.y - (self.height - 1)
                self.y = self.height - 1

            if num == 0:
                break

            self.direction = (self.direction - 90) % 360

    def getPos(self) -> List[int]:
        return [self.x, self.y]

    def getDir(self) -> str:
        return self.directions[self.direction]
