"""
Jeffrey Harmon
SDEV220
GeometricFigure.py
Apr. 11, 2021
"""
from tkinter import *

# Title
print("Draw some figures")

# Main class


class GeometricFigure:
    def __init__(self):
        # Create window
        window = Tk()
        window.title("Geometric Figure")

        # Create canvas
        self.canvas = Canvas(window, width=400, height=200, bg="white")
        self.canvas.pack()

        # Create frame for buttons
        frame = Frame(window)
        frame.pack()

        # Initialize variables
        self.shape = IntVar()
        self.filled = BooleanVar()

        # Create buttons
        rDiamond = Radiobutton(frame, text="Diamond", variable=self.shape, value=1,
                               command=self.draw)
        rDiamond.grid(row=1, column=1)
        rTriangle = Radiobutton(frame, text="Triangle",
                                variable=self.shape, value=2, command=self.draw)
        rTriangle.grid(row=1, column=2)
        btFilled = Checkbutton(frame, text="Filled",
                               variable=self.filled, command=self.draw)
        btFilled.grid(row=1, column=3)

        # Pre-select diamond
        rDiamond.select()

        # Draw initial shape
        self.draw()

        # Start window loop
        window.mainloop()

    def draw(self):
        self.clearCanvas()
        if self.shape.get() == 1:
            self.drawDiamond()
        else:
            self.drawTriangle()

    def drawDiamond(self):
        self.canvas.create_polygon(20, 100, 200, 20, 380, 100, 200, 180,
                                   fill="gray50" if self.filled.get() else "white", outline="black")

    def drawTriangle(self):
        self.canvas.create_polygon(20, 180, 200, 20, 380, 180,
                                   fill="gray50" if self.filled.get() else "white", outline="black")

    def clearCanvas(self):
        self.canvas.delete("all")


GeometricFigure()
