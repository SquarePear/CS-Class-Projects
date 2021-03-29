"""
Jeffrey Harmon
SDEV220
Area.py
Mar. 28, 2021
"""

# Title
print("Rectangle area and perimeter calculator")

# Get user input
width = float(input("Enter the width: "))
height = float(input("Enter the height: "))

# Calculate results
area = width * height
perimeter = width * 2 + height * 2

# Print results
print("The area is", area, "m²")
print("The perimeter is", perimeter, "m")
