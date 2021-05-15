
class Stack:
    def __init__(self):
        self.__elements = []

    # Return true if the tack is empty
    def isEmpty(self) -> bool:
        return len(self.__elements) == 0

    # Returns the element at the top of the stack
    # without removing it from the stack.
    def peek(self) -> object:
        if self.isEmpty():
            return None
        else:
            return self.__elements[len(self.__elements) - 1]

    # Stores an element into the top of the stack
    def push(self, value: object):
        self.__elements.append(value)

    # Removes the element at the top of the stack and returns it
    def pop(self) -> object:
        if self.isEmpty():
            return None
        else:
            return self.__elements.pop()

    # Return the size of the stack
    def getSize(self) -> int:
        return len(self.__elements)
