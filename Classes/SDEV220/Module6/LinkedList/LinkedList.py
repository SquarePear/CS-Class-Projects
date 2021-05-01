class LinkedList:
    def __init__(self, list=None):
        self.__head: Node = None
        self.__tail: Node = None
        self.__size = 0

        # Add elements if given starting list
        if list != None:
            for e in list:
                self.addLast(e)

    def addFirst(self, e: object):
        # Set head to new node pointing to previous head
        self.__head = Node(e, self.__head)

        # Increase size
        self.__size += 1

        # If list was empty, set tail as well
        if self.__tail == None:
            self.__tail = self.__head

    def addLast(self, e: object):
        # Create new node
        node = Node(e)

        # If list is empty, set tail and head to node
        if self.__tail == None:
            self.__head = self.__tail = node
        # Else only set tail
        else:
            self.__tail.next = node
            self.__tail = node

        # Increase size
        self.__size += 1

    def insert(self, index: int, e: object):
        # If index is 0, add first
        if index == 0:
            self.addFirst(e)
        # If index is last, add last
        elif index >= self.__size:
            self.addLast(e)
        # Else add in correct position
        else:
            current = self.__nodeAt(index - 1)

            current.next = Node(e, current.next)

            # Increase size
            self.__size += 1

    def removeFirst(self):
        # Can't remove if empty
        if self.__size == 0:
            return None

        temp = self.__head
        self.__head = self.__head.next

        self.__size -= 1

        if self.__head == None:
            self.__tail = None

        return temp.element

    def removeLast(self):
        # Can't remove if empty
        if self.__size == 0:
            return None

        # Special if only one element
        if self.__size == 1:
            temp = self.__head
            self.__head = self.__tail = None
            self.__size = 0

            return temp.element

        current = self.__head

        for _i in range(self.__size - 2):
            current = current.next

        temp = self.__tail
        self.__tail = current
        self.__tail.next = None
        self.__size -= 1

        return temp.element

    def removeAt(self, index: int):
        # Can't remove if out of range
        if index < 0 or index >= self.__size:
            return None

        # If index is 0, remove first
        if index == 0:
            return self.removeFirst()

        # If index is last, remove last
        if index == self.__size - 1:
            return self.removeLast()

        previous = self.__head

        for _i in range(1, index):
            previous = previous.next

        current = previous.next
        previous.next = current.next

        self.__size -= 1

        return current.element

    def isEmpty(self):
        return self.__size == 0

    def getSize(self):
        return self.__size

    def __str__(self):
        result = "["

        current = self.__head

        for _i in range(self.__size):
            result += str(current.element)
            current = current.next

            if current != None:
                result += ", "
            else:
                result += "]"

        return result

    def clear(self):
        self.__head = self.__tail = None
        self.__size = 0

    def contains(self, e: object):
        return self.indexOf(e) != -1

    def remove(self, e: object):
        return self.removeAt(self.indexOf(e))

    def get(self, index: int):
        if index < 0 or index >= self.__size:
            return None

        node = self.__nodeAt(index)

        return node.element

    def indexOf(self, e: object):
        if self.__head.element == e:
            return 0

        current = self.__head

        for i in range(1, self.__size):
            current = current.next

            if current.element == e:
                return i

        return -1

    def lastIndexOf(self, e: object):
        index = -1

        if self.__head.element == e:
            index = 0

        current = self.__head

        for i in range(1, self.__size):
            current = current.next

            if current.element == e:
                index = i

        return index

    def set(self, index: int,  e: object):
        if index < 0 or index >= self.__size:
            return False

        self.__nodeAt(index).element = e

        return True

    def __nodeAt(self, index: int):
        # Return None if out of bounds
        if index < 0 or index >= self.__size:
            return None

        # If index is 0, return first
        if index == 0:
            return self.__head

        # If index is last, return last
        if index == self.__size - 1:
            return self.__head

        current = self.__head

        for _i in range(1, index):
            current = current.next

        return current

    def __iter__(self):
        return LinkedListIterator(self.__head)

    def addAll(self, otherList: "LinkedList"):
        if otherList.getSize() == 0:
            return False

        # Add each element in list
        for e in otherList:
            self.addLast(e)

        return True

    def removeAll(self, otherList: "LinkedList"):
        if otherList.getSize() == 0:
            return False

        result = False

        # Remove each element in list
        for e in otherList:
            if self.indexOf(e) != -1:
                self.remove(e)
                result = True

        return result

    def retainAll(self, otherList: "LinkedList"):
        if otherList.getSize() == 0:
            self.clear()
            return True

        # Keep each element included in otherList
        for i in range(self.__size):
            if not otherList.contains(self.get(i)):
                self.removeAt(i)


class Node:
    def __init__(self, element: object, next: "Node" = None):
        self.element = element
        self.next = next


class LinkedListIterator:
    def __init__(self, head: Node):
        self.current = head

    def __next__(self):
        if (self.current == None):
            raise StopIteration

        element = self.current.element
        self.current = self.current.next

        return element
