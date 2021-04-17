from GeometricObject import GeometricObject
import math


class Triangle(GeometricObject):
    def __init__(self, side1=2.0, side2=2.0, side3=2.0, color="green", filled=True):
        super().__init__(color, filled)
        self.__side1 = side1
        self.__side2 = side2
        self.__side3 = side3

    def getArea(self):
        # Calculate area
        s = (self.__side1 + self.__side2 + self.__side3) / 2.0

        return math.sqrt(s * (s - self.__side1) * (s - self.__side2) * (s - self.__side3))

    def getPerimeter(self):
        # Calculate perimeter
        return self.__side1 + self.__side2 + self.__side3

    def __str__(self):
        # Display tri
        return "Triangle: a = " + str(self.__side1) + " b = " + str(self.__side2) + " c = " + str(self.__side3) + " " + super().__str__()
