class StringIterator:
    def __init__(self, compressed_string: str):
        self.__encoded_runs = []

        prev = len(compressed_string)
        curr = prev - 1

        while curr >= 0:
            while compressed_string[curr].isdigit():
                curr -= 1

            self.__encoded_runs.append(
                [
                    compressed_string[curr],
                    int(compressed_string[curr + 1 : prev]),
                ]
            )

            prev = curr
            curr -= 1

    def next(self) -> str:
        if not self.__encoded_runs:
            return " "

        self.__encoded_runs[-1][1] -= 1
        c, count = self.__encoded_runs[-1]

        if count == 0:
            self.__encoded_runs.pop()

        return c

    def hasNext(self) -> bool:
        return bool(self.__encoded_runs)
