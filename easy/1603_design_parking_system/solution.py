class ParkingSystem:
    def __init__(self, big: int, medium: int, small: int):
        self.__parking = {1: big, 2: medium, 3: small}

    def addCar(self, car_type: int) -> bool:
        if not self.__parking[car_type]:
            return False

        self.__parking[car_type] -= 1
        return True
