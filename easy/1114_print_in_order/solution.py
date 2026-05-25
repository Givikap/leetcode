import time
from typing import Callable


class Foo:
    def __init__(self):
        self.state = 0

    def first(self, printFirst: "Callable[[], None]") -> None:
        printFirst()
        self.state = 1

    def second(self, printSecond: "Callable[[], None]") -> None:
        while self.state != 1:
            time.sleep(0.1)

        printSecond()
        self.state = 2

    def third(self, printThird: "Callable[[], None]") -> None:
        while self.state != 2:
            time.sleep(0.1)

        printThird()
        self.state = 3
