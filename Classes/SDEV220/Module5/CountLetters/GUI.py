from tkinter import *
from tkinter import messagebox
from tkinter.filedialog import askopenfilename
import os

# Main class


class GUI:
    def __init__(self):
        # Define color scheme
        self.colors = ("white", "#323232")

        # Create window
        window = Tk()
        window.title("Count Letters")
        window.minsize(650, 375)

        # Create canvas
        self.canvas = Canvas(window, width=650, height=325, bg=self.colors[1])
        self.canvas.pack()

        # Create frame for buttons
        frame = Frame(window)
        frame.pack()

        # Initialize variables
        self.filename = StringVar(value="Mary lamb.txt")
        self.counts = [0] * 26

        # Create text field
        tFilename = Entry(frame, width=42, textvariable=self.filename)
        tFilename.grid(row=1, column=1)

        # Create buttons
        btFilename = Button(frame, text="Browse", command=self.getFilename)
        btFilename.grid(row=1, column=2)

        btResult = Button(frame, text="Show Result", command=self.result)
        btResult.grid(row=1, column=3)

        # Draw graph
        self.result()

        # Start window loop
        window.mainloop()

    def getFilename(self):
        self.filename.set(askopenfilename())

    def result(self):
        self.count()

        self.draw()

    def count(self):
        if not os.path.isfile(self.filename.get()):
            messagebox.showerror("File error", "File does not exist!")
            return

        file = open(self.filename.get(), "r")
        self.counts = [0] * 26

        for char in file.read().lower():
            if char.isalpha():
                self.counts[ord(char) - ord('a')] += 1

        file.close()

    def draw(self):
        self.clearCanvas()

        canvasWidth = int(self.canvas.cget("width"))
        canvasHeight = int(self.canvas.cget("height")) - 25

        width = canvasWidth / (len(self.counts) + 2)
        height = canvasHeight / (max(self.counts) + 1) * 0.9

        for i in range(0, len(self.counts)):
            pos1 = (width * (i+1), canvasHeight)
            pos2 = (width * (i+2), canvasHeight - (height * self.counts[i]))
            self.canvas.create_rectangle(
                pos1[0], pos1[1], pos2[0], pos2[1], fill=self.colors[1], outline=self.colors[0])
            self.canvas.create_text(
                (pos1[0] + pos2[0]) / 2, canvasHeight + 12.5, text=f"{chr(ord('a') + i)}", fill=self.colors[0])

    def clearCanvas(self):
        self.canvas.delete("all")
