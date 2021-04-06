"""
Jeffrey Harmon
SDEV220
RacingCar.py
Apr. 11, 2021
"""
from tkinter import *

# Title
print("Draw a racing car")

# Main class


class RacingCar:
    def __init__(self):
        # Create window
        window = Tk()
        window.title("Racing Car")

        # Create canvas
        width = 400
        self.canvas = Canvas(window, width=width, height=200, bg="white")
        self.canvas.pack()

        # Bind key event
        window.bind("<Key>", self.keyPressed)

        # Initialize variables
        self.x = -20
        self.speed = 5

        self.draw()

        # Animation loop
        while True:
            self.canvas.move("car", self.speed, 0)
            self.canvas.after(30)
            self.canvas.update()

            if self.x < width + 20:
                self.x += self.speed
            else:
                self.x = -20
                self.draw()

        # Start window loop
        window.mainloop()

    def draw(self):
        self.clearCanvas()
        self.canvas.create_oval(
            self.x - 15, 190, self.x - 5, 200, fill="gray50", outline="gray75", tags="car")
        self.canvas.create_oval(
            self.x + 5, 190, self.x + 15, 200, fill="gray50", outline="gray75", tags="car")
        self.canvas.create_polygon(
            self.x - 20, 195, self.x - 15, 185, self.x + 15, 185, self.x + 20, 195, fill="red", tags="car")

    def clearCanvas(self):
        self.canvas.delete("car")

    def keyPressed(self, event):
        key = event.keysym

        if key == "Up":
            self.speed += 0.5
        elif key == "Down":
            self.speed -= 0.5

        if self.speed <= 0:
            self.speed = 0.5


RacingCar()
