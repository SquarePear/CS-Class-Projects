"""
Jeffrey Harmon
SDEV220
GameLottery.py
Mar. 28, 2021
"""

import random

# Generate random three digit number
lotteryNum = random.randint(111, 999)

# Get user guess
guess = int(input("Input a three digit guess: "))

# Verify three digits
if (guess < 111 or guess > 999):
    print("Invalid input")
    exit()

winnings = 0

# Determine winnings
if (guess == lotteryNum):  # If in same order
    winnings = 10000
elif (sorted(str(guess)) == sorted(str(lotteryNum))):  # If out of order
    winnings = 7500
else:
    tempNums = str(lotteryNum)
    numMatch = 0
    for i in range(0, 3):
        index = tempNums.find(str(guess)[i])  # Find match
        if (index != -1):
            numMatch += 1
            # Cut out matches to stop ex. 123 <- 114
            tempNums = tempNums[0: index:] + tempNums[index + 1::]
    if (numMatch >= 2):  # If two matches
        winnings = 2000

# Print numbers
print(f"The winning number is {lotteryNum}")
print(f"You guessed {guess}")

# Print result
if (winnings > 0):
    print(f"You won ${winnings}")
else:
    print("You didn't win")
