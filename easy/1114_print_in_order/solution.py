from typing import Callable


class Foo:
    def __init__(self):
        self.called = [0] * 3

    def first(self, printFirst: "Callable[[], None]") -> None:
        printFirst()
        self.called[0] = 1

    def second(self, printSecond: "Callable[[], None]") -> None:
        while not self.called[0]:
            pass

        printSecond()
        self.called[1] = 1

    def third(self, printThird: "Callable[[], None]") -> None:
        while not self.called[1]:
            pass

        printThird()
        self.called[2] = 1
