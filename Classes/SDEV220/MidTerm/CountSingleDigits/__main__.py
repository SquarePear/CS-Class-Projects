"""
Jeffrey Harmon
SDEV220
CountSingleDigits.py
Apr. 18, 2021
"""

import random

# Title
print("Count Single Digits 1000 times", end="\n\n")

# Calculations
counts = [0] * 10

for i in range(0, 1000):
    counts[random.randint(0, 9)] += 1


# Print results
print("Results:")
for i in range(0, len(counts)):
    print(f"{i}s: {counts[i]} times")
