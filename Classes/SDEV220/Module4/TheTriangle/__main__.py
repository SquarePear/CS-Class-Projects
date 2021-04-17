"""
Jeffrey Harmon
SDEV220
TheTriangle.py
Apr. 18, 2021
"""

from Triangle import Triangle

# Title
print("Create a triangle!", end="\n\n")

triangle = None

# Get user input
while triangle == None:
    try:
        triangle = Triangle(
            float(input("Enter side 1: ")),
            float(input("Enter side 2: ")),
            float(input("Enter side 3: ")),
            input("Enter a color: "),
            True if int(input("Filled? (1 for yes): ")) == 1 else False
        )
    except:
        print("Invalid input. Try again!", end="\n\n")

# Print results
print("\n\n")
print(triangle)
print(f"Area: {triangle.getArea()}")
print(f"Perimeter: {triangle.getPerimeter()}")
