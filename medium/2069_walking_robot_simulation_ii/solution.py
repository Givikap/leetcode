from typing import List


class Robot:
    directions = {0: "North", 90: "East", 180: "South", 270: "West"}

    def __init__(self, width: int, height: int):
        self.width = width
        self.height = height

        self.x = 0
        self.y = 0
        self.direction = 90

    def step(self, num: int) -> None:
        if self.direction == 0:
            self.y += num
        elif self.direction == 90:
            self.x += num
        elif self.direction == 180:
            self.y -= num
        elif self.direction == 270:
            self.x -= num

        if self.x < 0:
            num = abs(self.x)
            self.x = 0
        elif self.x >= self.width:
            num = self.x - (self.width - 1)
            self.x -= num
        elif self.y < 0:
            num = abs(self.y)
            self.y = 0
        elif self.y >= self.height:
            num = self.y - (self.height - 1)
            self.y -= num
        else:
            num = 0

        if num:
            self.direction = (self.direction - 90) % 360
            self.step(num)

    def getPos(self) -> List[int]:
        return [self.x, self.y]

    def getDir(self) -> str:
        return self.directions[self.direction]
