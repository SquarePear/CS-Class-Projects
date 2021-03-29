"""
Jeffrey Harmon
SDEV220
Pentagon.py
Mar. 28, 2021
"""

import math

# Title
print("Pentagon area and perimeter calculator")

# Get user input
radius = float(input("Enter the radius: "))

# Calculate results
side = 2 * radius * math.sin(math.pi / 5)
area = ((3 * 3 ** 0.5) / 2) * side ** 2
perimeter = side * 5

# Print results
print("The length of a side is", format(side, ".2f"), "m")
print("The area is", format(area, ".2f"), "m²")
print("The perimeter is", format(perimeter, ".2f"), "m")
