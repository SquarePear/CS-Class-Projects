"""
Jeffrey Harmon
SDEV220
Circles.py
Mar. 28, 2021
"""

from turtle import Turtle

# Title
print("Four Circles")

# Get user input
radius = float(input("Enter the radius: "))

# Initialize turtle (Helps with IDE linter)
pen = Turtle()

# Draw circles
pen.pensize(2)
pen.penup()
pen.goto(-radius, 0)
pen.pendown()
for i in range(0, 4):
    pen.circle(radius)
    pen.penup()
    pen.forward(radius)
    pen.left(90)
    pen.forward(radius)
    pen.right(180)
    pen.pendown()

input("Press ENTER to continue...")
