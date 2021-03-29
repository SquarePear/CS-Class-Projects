"""
Jeffrey Harmon
SDEV220
Hexagon.py
Mar. 28, 2021
"""

from turtle import Turtle

# Title
print("Hexagon calculator")

# Get user input
side = float(input("Enter a side: "))

# Calculate results
area = ((3 * 3 ** 0.5) / 2) * side ** 2
perimeter = side * 6

# Print results
print("The area is", format(area, ".2f"), "m²")
print("The perimeter is", format(perimeter, ".2f"), "m")


# Initialize turtle (Helps with IDE linter)
pen = Turtle()

# Hide turtle
pen.hideturtle()

# Draw hexagon
pen.pensize(2)
pen.penup()
pen.goto(-side / 2, side / 2)
pen.pendown()
for i in range(0, 6):
    pen.forward(side)
    pen.right(60)


input("Press ENTER to continue...")
