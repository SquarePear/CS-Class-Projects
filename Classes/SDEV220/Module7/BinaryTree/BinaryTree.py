class BinaryTree:
    def __init__(self):
        self.__size = 0
        self.__root = None  # type: Node

    def insert(self, element: object):
        if self.__root == None:
            self.__root = Node(element)
            self.__size += 1

            return True

        parent = current = self.__root

        while current != None:
            parent = current

            if element < current.element:
                current = current.left
            elif element > current.element:
                current = current.right
            else:
                return False

        if element < parent.element:
            parent.left = Node(element)
        elif element > parent.element:
            parent.right = Node(element)

        self.__size += 1
        return True

    def search(self, element: object):
        current = self.__root

        while current != None:
            if element < current.element:
                current = current.left
            elif element > current.element:
                current = current.right
            else:
                return True

        return False

    def inorder(self):
        self.__inorderHelper(self.__root)

    def __inorderHelper(self, node: "Node"):
        if node == None:
            return

        self.__inorderHelper(node.left)
        print(node.element, end=" ")
        self.__inorderHelper(node.right)

    def postorder(self):
        self.__postorderHelper(self.__root)

    def __postorderHelper(self, node: "Node"):
        if node == None:
            return

        self.__postorderHelper(node.left)
        self.__postorderHelper(node.right)
        print(node.element, end=" ")

    def preorder(self):
        self.__preorderHelper(self.__root)

    def __preorderHelper(self, node: "Node"):
        if node == None:
            return

        print(node.element, end=" ")
        self.__preorderHelper(node.left)
        self.__preorderHelper(node.right)

    def path(self, element: object):
        list = []
        current = self.__root

        while current != None:
            list.append(current)

            if element < current.element:
                current = current.left
            elif element > current.element:
                current = current.right
            else:
                break

        return list

    def delete(self, element: object):
        parent = None
        current = self.__root

        while current != None:
            if element < current.element:
                parent = current
                current = current.left
            elif element > current.element:
                parent = current
                current = current.right
            else:
                break

        if current == None:
            return False

        if current.left == None:
            if parent == None:
                self.__root = current.right
            else:
                if element < parent.element:
                    parent.left = current.right
                else:
                    parent.right = current.right
        else:
            parentOfRightMost = current
            rightMost = current.left

            while rightMost.right != None:
                parentOfRightMost = rightMost
                rightMost = rightMost.right

            current.element = rightMost.element

            if parentOfRightMost.right == rightMost:
                parentOfRightMost.right = rightMost.left
            else:
                parentOfRightMost.left = rightMost.left

        self.__size -= 1
        return True

    def breadthFirstTraversal(self):
        queue = [self.__root]

        print(queue[0].element, end=" ")

        while len(queue) != 0:
            node = queue.pop(0)

            if node.left != None:
                print(node.left.element, end=" ")
                queue.append(node.left)

            if node.right != None:
                print(node.right.element, end=" ")
                queue.append(node.right)

    def height(self):
        return self.__heightHelper(self.__root)

    def __heightHelper(self, node: "Node", height=0):
        if node == None:
            return height

        return max(self.__heightHelper(node.left, height + 1), self.__heightHelper(node.right, height + 1))

    def isEmpty(self):
        return self.__size == 0

    def clear(self):
        self.__root = None
        self.__size = 0

    def getSize(self):
        return self.__size

    def getRoot(self):
        return self.__root


class Node:
    def __init__(self, element: object, left: "Node" = None, right: "Node" = None):
        self.element = element

        self.left = left
        self.right = right
