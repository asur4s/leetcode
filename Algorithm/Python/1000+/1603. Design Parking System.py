from enum import Enum

class ParkingSystem:
    class CarType(Enum):
        Big = 1
        Medium = 2
        Small = 3

    slotNum = {
        CarType.Big: 0,
        CarType.Medium: 0,
        CarType.Small: 0
    }

    def __init__(self, big: int, medium: int, small: int):
        self.slotNum[self.CarType.Big] = big 
        self.slotNum[self.CarType.Medium] = medium
        self.slotNum[self.CarType.Small] = small

    def addCar(self, carType: int) -> bool:
        carEnum = self.CarType(carType)
        if self.slotNum[carEnum] - 1 < 0:
            return False
        else:
            self.slotNum[carEnum] -= 1
            return True


# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)