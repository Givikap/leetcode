class ParkingSystem:
    def __init__(self, big: int, medium: int, small: int):
        self.__parking = [big, medium, small]

    def addCar(self, car_type: int) -> bool:
        if not self.__parking[car_type - 1]:
            return False

        self.__parking[car_type - 1] -= 1
        return True
