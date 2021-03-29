"""
Jeffrey Harmon
SDEV220
Clock.py
Mar. 28, 2021
"""

from turtle import Turtle

# Initialize turtle (Helps with IDE linter)
pen = Turtle()

# Hide turtle
pen.hideturtle()

# Draw hands
pen.pensize(2)
pen.goto(0, 200)
pen.goto(0, 0)
pen.pensize(4)
pen.goto(-150, 0)
pen.goto(0, 0)
pen.pensize(6)
pen.goto(0, -100)
pen.goto(0, 0)


# Define font style
style = ('Courier', 30, 'italic')

# Draw clock face
pen.pensize(2)
pen.penup()
pen.goto(0, 250)
pen.pendown()
pen.setheading(180)
for i in range(0, 4):
    pen.circle(250, -90)
    pen.write((i + 1) * 3, font=style, align='center')

# Draw digital time
pen.penup()
pen.goto(0, -300)
pen.write("6:45:00", font=style, align='center')


input("Press ENTER to continue...")
