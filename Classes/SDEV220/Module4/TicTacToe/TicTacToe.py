"""
Jeffrey Harmon
SDEV220
TicTacToe.py
Apr. 18, 2021
"""


class TicTacToe:
    def __init__(self, size=3, symbols=['✕', '◯']):
        self.size = size
        self.board = [0] * (size ** 2)
        self.symbols = symbols

    def getCell(self, x, y):
        if not (0 <= x < self.size and 0 <= y < self.size):
            return

        return self.board[x + y * self.size]

    def setCell(self, x, y, value, unsafe=False):
        if not (0 <= x < self.size and 0 <= y < self.size) or not (-1 <= value <= 1):
            return False

        if not unsafe and self.getCell(x, y) != 0:
            return False

        self.board[x + y * self.size] = value

        return True

    def getPlayerSymbol(self, value):
        if (value == -1):
            return self.symbols[0]
        elif (value == 1):
            return self.symbols[1]

        return " "

    def getCellSymbol(self, x, y):
        if not (0 <= x < self.size and 0 <= y < self.size):
            return

        value = self.getCell(x, y)

        return self.getPlayerSymbol(value)

    def displayBoard(self):
        for y in range(0, self.size):
            row = []

            for x in range(0, self.size):
                row.append(self.getCellSymbol(x, y))

            print(" " + " │ ".join(row))
            if (y < self.size - 1):
                print("───┼" * (self.size - 1) + "───")

    def getWinner(self):
        # Check vertical
        for x in range(0, self.size):
            count = 0
            for y in range(0, self.size):
                count += self.getCell(x, y)
            if (count == self.size or count == -self.size):
                return count / self.size

        # Check horizontal
        for y in range(0, self.size):
            count = 0
            for x in range(0, self.size):
                count += self.getCell(x, y)
            if (count == self.size or count == -self.size):
                return count / self.size

        # Check top to bottom diagonal
        count = 0
        for pos in range(0, self.size):
            count += self.getCell(pos, pos)
            if (count == self.size or count == -self.size):
                return count / self.size

        # Check bottom to top diagonal
        count = 0
        for pos in range(0, self.size):
            count += self.getCell(pos, (self.size - 1) - pos)
            if (count == self.size or count == -self.size):
                return count / self.size

        return 0

    def isFull(self):
        # return False if any cell isn't full
        for cell in self.board:
            if cell == 0:
                return False

        return True
