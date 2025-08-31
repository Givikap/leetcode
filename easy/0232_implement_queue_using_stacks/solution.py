class MyQueue:
    def __init__(self):
        self.stack = []
        self.queue = []

    def push(self, x: int) -> None:
        self.stack.append(x)

    def pop(self) -> int:
        if self.queue:
            return self.queue.pop()

        while self.stack:
            self.queue.append(self.stack.pop())

        return self.queue.pop()

    def peek(self) -> int:
        if self.queue:
            return self.queue[-1]

        while self.stack:
            self.queue.append(self.stack.pop())

        return self.queue[-1]

    def empty(self) -> bool:
        return not self.stack and not self.queue
