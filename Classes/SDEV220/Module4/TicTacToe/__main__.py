"""
Jeffrey Harmon
SDEV220
TicTacToe.py
Apr. 18, 2021
"""

from TicTacToe import TicTacToe


# Title
print("Time to play some Tic-Tac-Toe!", end="\n\n")

# Get board size
size = input("Enter the board size (3): ")

size = 3 if (size == '') else int(size)

game = TicTacToe(size)
player = -1

# Game loop
while (game.getWinner() == 0 and not game.isFull()):
    print("\n\n")
    game.displayBoard()
    print()
    print(f"Player {game.getPlayerSymbol(player)}'s turn!")

    try:
        row = int(input(f"Enter a row (1-{game.size}): ")) - 1
        col = int(input(f"Enter a column (1-{game.size}): ")) - 1

        if not game.setCell(col, row, player):
            raise Exception("Failed")

        player *= -1
    except:
        print("Invalid input! Try again!")

# Print results
print("\n\n")

game.displayBoard()

winner = game.getWinner()

print()

if winner == 0:
    print("Tie!")
else:
    print(f"Player {game.getPlayerSymbol(game.getWinner())} wins!", )
