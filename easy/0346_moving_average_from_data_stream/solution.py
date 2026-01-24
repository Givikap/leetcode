from collections import deque


class MovingAverage:
    def __init__(self, size: int):
        self.__queue = deque()
        self.__size = size

        self.__sum = 0

    def next(self, val: int) -> float:
        if len(self.__queue) == self.__size:
            self.__sum -= self.__queue.popleft()

        self.__queue.append(val)
        self.__sum += val

        return self.__sum / len(self.__queue)
