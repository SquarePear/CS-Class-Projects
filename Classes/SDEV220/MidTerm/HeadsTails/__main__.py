"""
Jeffrey Harmon
SDEV220
HeadsTails.py
Apr. 18, 2021
"""


def decToCoins(num):
    current = 256
    binary = []

    while current >= 1:
        binary.append("T" if num >= current else "H")

        if (num >= current):
            num -= current

        current /= 2

    return binary


# Title
print("Decimal to coins", end="\n\n")

# User input
num = int(input("Enter a number (0-511): "))

if (not 0 <= num < 512):
    exit()

# Calculations
coins = decToCoins(num)

# Print results
print("Results: ", end="\n\n")
print(f"{coins[0]} {coins[1]} {coins[2]}")
print(f"{coins[3]} {coins[4]} {coins[5]}")
print(f"{coins[6]} {coins[7]} {coins[8]}")
